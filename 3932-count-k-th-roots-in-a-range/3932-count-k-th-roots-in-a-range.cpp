class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int c=0;
        if(k==1) return r-l+1;
        for(int i=0;;i++){
            long long ans = (long long )pow((long long)i,(long long)k);
            if(ans>=l && ans<=r) c++;
            if(ans>r) break;
        }
        return c;
    }
};