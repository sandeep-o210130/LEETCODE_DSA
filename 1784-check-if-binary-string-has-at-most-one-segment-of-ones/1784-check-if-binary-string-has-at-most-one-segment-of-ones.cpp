class Solution {
public:
    bool checkOnesSegment(string s) {
        int c=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]) c++;
        }
        if((c>2) || ((c>1) && (s[0]=='1'))) return false;
        else return true;
    }
};