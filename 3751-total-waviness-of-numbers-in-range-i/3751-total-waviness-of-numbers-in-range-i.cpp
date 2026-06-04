class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int i=num1,j=num2;
        int c=0;
        while(i<=j){
            int c1=0,temp = i,prev = temp%10;
            temp/=10;
            while(temp){
                int curr = temp%10;
                temp/=10;
                if(temp!=0){
                    if(curr>prev && curr>(temp%10)) c1++;
                    else if(curr<prev && curr<(temp%10)) c1++;
                }
                prev = curr;
            }
            c+=c1;
            i++;
        }
        return c;
    }
};
