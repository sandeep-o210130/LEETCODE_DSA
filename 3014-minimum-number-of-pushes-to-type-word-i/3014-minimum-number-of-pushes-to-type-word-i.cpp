class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size(),c=0;
        for(int i=0;i<4 && n!=0 ;i++){
            if(n<8){
                c=c+(n*(i+1));
                n=0;
            }
            else {
                c=c+(8*(i+1));
                n-=8;
            }
        }
        return c;
    }
};