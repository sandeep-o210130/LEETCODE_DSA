class Solution {
public:
    int dist(int a, int b){
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int anss(vector<vector<vector<int>>> &dp, int i, int j, int k, string &word){
        if(k == word.size()) return 0;
        if(i != -1 && j != -1 && dp[i][j][k] != -1)
            return dp[i][j][k];

        int cur = word[k] - 'A';

        int cost1 = (i == -1 ? 0 : dist(i, cur)) +
                    anss(dp, cur, j, k + 1, word);

        int cost2 = (j == -1 ? 0 : dist(j, cur)) +
                    anss(dp, i, cur, k + 1, word);

        int res = min(cost1, cost2);

        if(i != -1 && j != -1)
            dp[i][j][k] = res;

        return res;
    }

    int minimumDistance(string word) {
        int n = word.size();

        vector<vector<vector<int>>> dp(
            26, vector<vector<int>>(26, vector<int>(n, -1))
        );

        return anss(dp, -1, -1, 0, word);
    }
};