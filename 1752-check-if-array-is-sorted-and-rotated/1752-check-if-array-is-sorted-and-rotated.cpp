class Solution {
public:
    bool check(vector<int>& nums) {
        int c=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                c=i;
                break;
            }
        }
        if(c==-1) return true;
        for(int i=1;i<nums.size();i++){
            if(nums[(c+i-1)%nums.size()]>nums[(c+i)%nums.size()]) return false;
        }
        return true;
    }
};