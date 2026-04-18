class Solution {
public:
    int mirrorDistance(int n) {
        int c1=n,c2=0;
        while(c1!=0){
            c2 = c2*10+(c1%10);
            c1/=10;
        }
        return abs(c2-n);
    }
};