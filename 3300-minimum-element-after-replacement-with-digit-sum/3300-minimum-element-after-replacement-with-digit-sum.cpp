class Solution {
public:
    int minElement(vector<int>& nums) {
        int minn=INT_MAX;
        for(auto i:nums){
            int ans=0;
            while(i!=0){
                ans=ans+(i%10);
                i/=10;
            }
            minn = min(minn,ans);
        }
        return minn;
    }
};