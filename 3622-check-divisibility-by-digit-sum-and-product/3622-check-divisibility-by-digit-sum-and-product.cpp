class Solution {
public:
    bool checkDivisibility(int n) {
        long long t=1,t2=0,m=n;
        while(m!=0){
            t=t*1LL*(m%10);
            t2=t2+(m%10);
            m/=10;
        }
        return !(n%(t+t2));
    }
};