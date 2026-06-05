class Solution {
public:
    struct Node {
        long long cnt, wav;
    };

    string s;
    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node dfs(int pos, int tight, int started,
             int prev2, int prev1) {

        if (pos == s.size())
            return {1, 0};

        if (vis[pos][tight][started][prev2][prev1])
            return dp[pos][tight][started][prev2][prev1];

        vis[pos][tight][started][prev2][prev1] = true;

        Node ans = {0, 0};

        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; d++) {

            int ntight = tight && (d == lim);

            if (!started && d == 0) {

                Node child =
                    dfs(pos + 1, ntight, 0, 10, 10);

                ans.cnt += child.cnt;
                ans.wav += child.wav;
            }
            else if (!started) {

                Node child =
                    dfs(pos + 1, ntight, 1, 10, d);

                ans.cnt += child.cnt;
                ans.wav += child.wav;
            }
            else {

                long long add = 0;

                if (prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                Node child =
                    dfs(pos + 1, ntight, 1, prev1, d);

                ans.cnt += child.cnt;
                ans.wav += child.wav +
                           child.cnt * add;
            }
        }

        return dp[pos][tight][started][prev2][prev1] = ans;
    }

    long long solve(long long n) {

        if (n < 0) return 0;

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};