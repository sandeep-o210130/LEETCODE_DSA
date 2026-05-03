class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal) return true;
        for(int i=1;i<s.size();i++){
            int c=0,c1=0;
            for(int j=s.size()-i;j<s.size();j++){
                if(s[j]!=goal[c]){
                    c1=1;
                    break;
                }
                c++;
            }
            for(int j=0;j<=s.size()-i-1;j++){
                if(s[j]!=goal[c]){
                    c1=1;
                    break;
                }
                c++;
            }
            if(c1==0) return true;
        }
        return false;
    }
};