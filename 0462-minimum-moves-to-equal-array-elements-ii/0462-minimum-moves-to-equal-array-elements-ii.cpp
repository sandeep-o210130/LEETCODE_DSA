class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int n = nums.size();
        nth_element(nums.begin(),nums.begin() + n / 2,nums.end());
        int med;
        med = nums[n / 2];
        
        int res = 0;
        for(int i = 0;i < n;i++){
            res += abs(med - nums[i]);
        }
        return res;
    }
};