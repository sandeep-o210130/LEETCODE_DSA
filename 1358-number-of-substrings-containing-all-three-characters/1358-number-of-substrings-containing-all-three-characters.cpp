class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0,c1=0,i=0,j=0;
        while(j<s.size()){
            (s[j]=='a')?a++:(s[j]=='b'?b++:(s[j]=='c'?c++:c));
            while(a>=1 && b>=1 && c>=1){
                c1=c1+(s.size()-j);
                (s[i]=='a')?a--:(s[i]=='b'?b--:(s[i]=='c'?c--:c));
                i++;
            }
            j++;
        }
        return c1;
    }
};