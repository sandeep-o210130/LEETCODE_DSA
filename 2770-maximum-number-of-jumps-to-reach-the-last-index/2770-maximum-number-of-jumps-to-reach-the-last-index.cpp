class Solution {
public:

    int solve(int i, vector<int>& nums, int target, vector<int>& dp) {

        int n = nums.size();

        if (i == n - 1) return 0;

        if (dp[i] != -2) return dp[i];

        int ans = -1;

        for (int j = i + 1; j < n; j++) {

            long long diff = abs((long long)nums[j] - nums[i]);

            if (diff <= target) {

                int next = solve(j, nums, target, dp);

                if (next != -1) {
                    ans = max(ans, 1 + next);
                }
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> dp(n, -2);

        return solve(0, nums, target, dp);
    }
};