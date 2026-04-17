class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int minn=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            int ele=nums[i],ele2=0;
            while(ele!=0){
                ele2 = (ele2*10)+(ele%10);
                ele/=10;
            }
            if(mpp.count(ele2))
                minn=min(minn,mpp[ele2]-i);
            mpp[nums[i]]=i;
        }
        if(minn==INT_MAX) return -1;
        return minn;
    }
};