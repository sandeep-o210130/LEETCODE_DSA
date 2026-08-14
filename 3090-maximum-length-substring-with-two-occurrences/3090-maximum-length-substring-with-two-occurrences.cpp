class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,r=0,c=0;
        unordered_map<char,int> mpp;
        while(l<s.size()){
            mpp[s[l]]++;
            while(mpp[s[l]]>2){
                mpp[s[r]]--;
                r++;
            }
            c=max(c,l-r+1);
            l++;
        }
        return c;
    }
};