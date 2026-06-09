class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxx=INT_MIN,minn =INT_MAX;
        for(auto i:nums){
            maxx=max((long long)maxx,(long long)i);
            minn = min((long long)minn,(long long)i);
        } 
        return (maxx-minn)*k;
    }
};