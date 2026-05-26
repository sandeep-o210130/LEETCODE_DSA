class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> temp(128,0),t(128,0);
        int c=0;
        for(auto i:word){
            if(i>=65 && i<=90){
                if(!temp[i] && temp[i+32]){
                    t[i+32]=1;
                    c++;
                }
                temp[i]++;
            }
            else{
                temp[i]++;
                if(t[i]==1){
                    c--;
                    t[i]=0;
                }
            }
        }
        return c;
    }
};