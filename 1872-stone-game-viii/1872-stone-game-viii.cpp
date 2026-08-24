class Solution {
public:
    int stoneGameVIII(vector<int>& s) {
        int n = s.size();
        vector<long long> dp(n);
        dp[0] = s[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + s[i];
        }
        long long ans = dp[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            ans = max(ans, dp[i] - ans);
        }
        return ans;
    }
};