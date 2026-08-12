class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,long long> mpp;
        int maxx=0,l=0,r=0;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp[nums[r]]>k){
                mpp[nums[l]]--;
                l++;
            }
            maxx=max(maxx,r-l+1);
            r++;
        }
        maxx=max(maxx,r-l);
        return maxx;
    }
};