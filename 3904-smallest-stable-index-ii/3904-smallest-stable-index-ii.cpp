class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> l(nums.size()),s(nums.size());
        int maxx=INT_MIN,minn=INT_MAX,ans=-1;
        for(int i=0;i<nums.size();i++){
            maxx = max(maxx,nums[i]);
            l[i]=maxx;
        }
        for(int i=nums.size()-1;i>=0;i--){
            minn = min(minn,nums[i]);
            s[i]=minn;
        }
        for(int i=0;i<nums.size();i++){
            if((l[i]-s[i])<=k){
                ans=i;
                break;
            }
        }
        return ans;
    }
};