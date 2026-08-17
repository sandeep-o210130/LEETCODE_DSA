class Solution {
public:
    int solve(vector<int>& prefix, int i, int j,
              vector<vector<int>>& dp) {

        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i; k < j; k++) {

            int leftSum = prefix[k] - (i > 0 ? prefix[i - 1] : 0);
            int rightSum = prefix[j] - prefix[k];

            if (leftSum < rightSum) {
                ans = max(ans, leftSum + solve(prefix, i, k, dp));
            }
            else if (leftSum > rightSum) {
                ans = max(ans, rightSum + solve(prefix, k + 1, j, dp));
            }
            else {
                ans = max(ans,
                    leftSum + max(
                        solve(prefix, i, k, dp),
                        solve(prefix, k + 1, j, dp)
                    )
                );
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();
        
        for (int i = 1; i < n; i++)
            stoneValue[i] += stoneValue[i - 1];

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(stoneValue, 0, n - 1, dp);
    }
};