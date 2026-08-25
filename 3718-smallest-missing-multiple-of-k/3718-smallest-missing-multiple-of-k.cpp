class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> ans;
        for(auto i:nums) if(!(i%k)) ans[i/k]=1;
        for(int i=1;i<=nums.size();i++){
            if(ans.find(i)==ans.end()) return k*i;
        }
        return k*(nums.size()+1);
    }
};