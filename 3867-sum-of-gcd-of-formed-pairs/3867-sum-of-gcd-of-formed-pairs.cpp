class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long sum=0;
        vector<int> pre(nums.size());
        int maxx=0;
        for(int i=0;i<pre.size();i++){
            maxx = max(maxx,nums[i]);
            pre[i]=__gcd(maxx,nums[i]);
        }
        sort(pre.begin(),pre.end());
        int n = (nums.size()/2)-1;
        for(int i=0;i<=n;i++) sum=sum+__gcd(pre[i],pre[nums.size()-1-i]);
        return sum;
    }
};