class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]].push_back(i);
        int minn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int ele=nums[i],ele2=0;
            while(ele!=0){
                ele2 = (ele2*10)+(ele%10);
                ele/=10;
            }
            int idx = INT_MIN;
            if(mpp.find(ele2)!=mpp.end())
                idx = upper_bound(mpp[ele2].begin(),mpp[ele2].end(),i)-mpp[ele2].begin();   
            if((idx!=INT_MIN) && (idx!=mpp[ele2].size()))
                minn = min(minn,(mpp[ele2][idx]-i));
        }
        if(minn==INT_MAX) return -1;
        return minn;
    }
};