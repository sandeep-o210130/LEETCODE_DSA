class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1) return 0;

        long long prod = 1;

        int left = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right++) {

            prod *= nums[right];

            while(prod >= k) {
                prod /= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};