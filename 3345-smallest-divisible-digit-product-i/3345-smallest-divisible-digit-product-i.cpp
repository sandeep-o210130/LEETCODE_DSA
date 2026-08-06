class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            long long t1=1;
            int s=n;
            while(s!=0){
                t1=t1*(s%10);
                s/=10;
            }
            if((t1%t)==0) return n;
            n++;
        }
    }
};