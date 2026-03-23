class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long minne=LLONG_MAX,minno=LLONG_MAX;
        for(auto i:nums1){
            if(i%2) minno = min((long long)minno,(long long) i);
            else minne = min((long long) minne,(long long) i);
        }
        if(minne==LLONG_MAX || minno==LLONG_MAX) return true;
        else if(minne>minno) return true;
        return false;
    }
};