class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        for(int i=1;i<nums.size();i++) nums[i]=nums[i]+nums[i-1];
        int s=0,e=nums.size()-1;
        while(s<=e){
            int i= (s+e)/2,c=0;
            if(nums[i]>=target) c=1;
            if(c==0){
                for(int j=i+1;j<nums.size();j++){
                    if((nums[j]-nums[j-i-1])>=target){
                        c=1;
                        break;
                    }
                }
            }
            if(c>0) e=i-1;
            else s=i+1;
        }
        if(s>(nums.size()-1)) return 0;
        return s+1;
    }
};