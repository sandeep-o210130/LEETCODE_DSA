class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]].push_back(i);
            int minn=INT_MAX;
            for(auto [i,j]:mpp){
                if(j.size()>2){
                    for(int k=0;k<j.size()-2;k++){
                        minn = min(minn,(j[k+1]-j[k])+(j[k+2]-j[k+1])+(j[k+2]-j[k]));
                    }
                }
            }
            if(minn==INT_MAX) return -1;
            return minn;
    }
};