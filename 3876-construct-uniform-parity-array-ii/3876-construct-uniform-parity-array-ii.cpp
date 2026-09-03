class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool temp=false;
        int t=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]&1){
                temp=true;
                t=min(t,nums1[i]);
            }
        }
        if(t==INT_MAX) return true;
        for(auto i:nums1) if(i<t) return false;
        return true;
    }
};