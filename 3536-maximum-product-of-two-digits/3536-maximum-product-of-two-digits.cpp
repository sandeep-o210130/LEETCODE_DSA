class Solution {
public:
    int maxProduct(int n) {
        int maxx1=-1,maxx2=-1,c=0;
        while(n!=0){
            int ele = n%10;
            if(ele>maxx1){
                maxx2=maxx1;
                maxx1=ele;
                c=1;
            }
            if((ele>maxx2) && (c!=1)) maxx2=ele;
            c=0;
            n/=10;
        }
        return maxx1*maxx2;
    }
};