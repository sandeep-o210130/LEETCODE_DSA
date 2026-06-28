class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long c=0;
        for(int i=0;i<k;i++){
            if(mul>=1) c=c+(long long) mul*nums[i];
            else c=c+nums[i];
            mul--;
        }
        return c;
    }
};