class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long a= accumulate(nums.begin(),nums.end(),(long long) 0),ans=0;
        if(a==0) return a;
        for(auto i:nums) ans=ans^i;
        return (ans)?nums.size():nums.size()-1;
    }
};