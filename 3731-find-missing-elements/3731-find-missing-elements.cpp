class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxx = *max_element(nums.begin(),nums.end()), 
        minn = *min_element(nums.begin(),nums.end());
        vector<int> temp(maxx+1,0),ans;
        for(auto i:nums) temp[i]=1;
        for(int i=minn;i<=maxx;i++) if(temp[i]==0) ans.push_back(i);
        return ans;
    }
};