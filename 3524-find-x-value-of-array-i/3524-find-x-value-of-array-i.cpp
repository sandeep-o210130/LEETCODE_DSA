class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k);

        for (int x : nums) {
            vector<long long> cur(k);
            int r = x % k;

            cur[r]++;

            for (int j = 0; j < k; j++)
                cur[j * r % k] += dp[j];

            for (int j = 0; j < k; j++)
                ans[j] += cur[j];

            dp = cur;
        }

        return ans;
    }
};