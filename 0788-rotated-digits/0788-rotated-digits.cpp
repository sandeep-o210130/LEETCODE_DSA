class Solution {
public:
    int rotatedDigits(int n) {
        int c=0;
        for(int i=1;i<=n;i++){
            int temp=i,c1=0;
            while(temp!=0){
                int rem = temp%10;
                if(rem==3 || rem==7 || rem==4){
                    c1=0;
                    break;
                }
                else if(rem==2 || rem==5 || rem==6 || rem==9) c1=1;
                temp/=10;
            }
            if(c1) c++;
        }
        return c;
    }
};