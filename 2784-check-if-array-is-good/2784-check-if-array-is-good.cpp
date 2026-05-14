class Solution {
public:
    bool isGood(vector<int>& nums) {
        int  n =-1;
        for(auto i:nums) n = max(n,i);
        vector<int> temp(n+1,0);
        for(auto i:nums) temp[i]++;
        for(int i=1;i<n;i++){
            if(temp[i]!=1) return false;
        }
        if(temp[n]!=2) return false;
        return true;
    }
};