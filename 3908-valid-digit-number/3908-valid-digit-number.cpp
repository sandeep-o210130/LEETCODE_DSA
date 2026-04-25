class Solution {
public:
    bool validDigit(int n, int x) {
        bool ans=false;
        int prev=n;
        while(n>0){
            prev=n;
            if((n%10)==x) ans=true;
            n/=10;
        }  
        if((prev!=x) && (ans==true)) return true;
        return false;
    }
};