class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int res = n + 1;
        int total = 0;
        int i = 0;

        vector<int> dp(n + 1, n);

        for (int j = 0; j < n; j++) {
            total += arr[j];

            while (total > target) {
                total -= arr[i];
                i++;
            }

            dp[j + 1] = dp[j];

            if (total == target) {
                int len = j - i + 1;

                res = min(res, len + dp[i]);
                dp[j + 1] = min(dp[j], len);
            }
        }

        return res == n + 1 ? -1 : res;
    }
};