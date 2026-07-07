class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0,sum=0,c=0;
        while(n!=0){
            if((n%10)!=0){
                sum=sum+(n%10);
                num=((n%10)*(long long) pow(10,c))+num;
                c++;
            }
            n=n/10;
        }
        return sum*1LL*num;
    }
};