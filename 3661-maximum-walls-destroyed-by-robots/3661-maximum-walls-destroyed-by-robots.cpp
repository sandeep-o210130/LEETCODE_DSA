class Solution {
public:
    int count_walls(const vector<int>& walls, long long l, long long r) {
        if (l > r) 
            return 0;
        auto it_l = lower_bound(walls.begin(), walls.end(), (int)l);
        auto it_r = upper_bound(walls.begin(), walls.end(), (int)r);
        return (int)distance(it_l, it_r);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        if (n == 0) 
            return 0;

        sort(walls.begin(), walls.end());

        vector<pair<long long, int>> r_data(n);
        for (int i = 0; i < n; ++i) {
            r_data[i] = {robots[i], distance[i]};
        }
        sort(r_data.begin(), r_data.end());

        vector<vector<int>> dp(n, vector<int>(2, 0));

        long long INF = 2e18;
        long long pos0 = r_data[0].first;
        int dist0 = r_data[0].second;
        long long next_r = (n > 1) ? r_data[1].first : INF;

        dp[0][0] = count_walls(walls, pos0 - dist0, pos0);
        dp[0][1] = count_walls(walls, pos0, min(pos0 + dist0, next_r - 1));

        for (int i = 1; i < n; ++i) {
            long long cur_p = r_data[i].first;
            int cur_d = r_data[i].second;
            long long pre_p = r_data[i - 1].first;
            int pre_d = r_data[i - 1].second;
            next_r = (i + 1 < n) ? r_data[i + 1].first : INF;

            int r_gain = count_walls(walls, cur_p, min(cur_p + cur_d, next_r - 1));
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + r_gain;

            long long l_lim = max(cur_p - cur_d, pre_p + 1);
            int l_gain = count_walls(walls, l_lim, cur_p);

            dp[i][0] = dp[i - 1][0] + l_gain;

            long long over_l = l_lim;
            long long over_r = min(pre_p + (long long)pre_d, cur_p - 1);
            int overlap = count_walls(walls, over_l, over_r);

            dp[i][0] = max(dp[i][0], dp[i - 1][1] + l_gain - overlap);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};