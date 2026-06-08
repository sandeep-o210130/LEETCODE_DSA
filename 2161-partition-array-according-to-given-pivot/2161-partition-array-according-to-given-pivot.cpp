class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less,right,ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) less.push_back(nums[i]);
            if(nums[i]>pivot) right.push_back(nums[i]);
        }
        for(auto i:less) ans.push_back(i);
        for(int i=less.size()+right.size();i<nums.size();i++) ans.push_back(pivot);
        for(auto i:right) ans.push_back(i);
        return ans;
    }
};