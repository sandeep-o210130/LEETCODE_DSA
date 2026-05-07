class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> preMax(n);
        vector<int> ans(n);

        preMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        int sufMin = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            if (preMax[i] > sufMin) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = preMax[i];
            }
            sufMin = min(sufMin, nums[i]);
        }
        return ans;
    }
};