class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==2) return nums.size();
        return pow(2,(int)log2(nums.size())+1);
    }
};