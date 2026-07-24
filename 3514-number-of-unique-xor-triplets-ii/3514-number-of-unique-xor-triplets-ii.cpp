class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> sett,sett2;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++) sett.insert(nums[i]^nums[j]);
        }
        for(int i=0;i<nums.size();i++){
            for(auto j:sett){
                sett2.insert(nums[i]^j);
            }
        }
        return sett2.size();
    }
};