class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++) mpp[nums[i]].push_back(i);
        vector<long long> ans(n);

        for(auto &p : mpp){
            vector<int>& temp = p.second;
            int sz = temp.size();
            vector<long long> pre(sz);
            pre[0] = temp[0];
            for(int i=1;i<sz;i++) pre[i]=pre[i-1]+temp[i];

            for(int i=0;i<sz;i++){
                long long sum=0;
                if(i>0) sum += (long long)temp[i]*i - pre[i-1];
                if(i<sz-1) sum += (pre[sz-1]-pre[i]) - (long long)temp[i]*(sz-i-1);
                ans[temp[i]] = sum;
            }
        }
        return ans;
    }
};