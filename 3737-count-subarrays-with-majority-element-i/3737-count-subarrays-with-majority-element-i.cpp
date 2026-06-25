class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            int t=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target) t++;
                if((2*t)>(j-i+1)) c++;
            }
        }
        return c;
    }
};