class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])!=mpp.end()) return {mpp[target-nums[i]]-1,i};
            mpp[nums[i]]=i+1;
        }  
        return {0,0};
    }
};