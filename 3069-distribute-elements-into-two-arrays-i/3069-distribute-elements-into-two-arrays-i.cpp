class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> t1,t2;
        t1.push_back(nums[0]);
        t2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(t1.back()>t2.back()) t1.push_back(nums[i]);
            else t2.push_back(nums[i]);
        }
        for(auto i:t2) t1.push_back(i);
        return t1;
    }
};