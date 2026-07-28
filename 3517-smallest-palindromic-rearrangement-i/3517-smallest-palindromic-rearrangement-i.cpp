class Solution {
public:
    string smallestPalindrome(string s1) {
        vector<int> a(26,0);
        for(auto i:s1) a[i-'a']++;
        string s="",temp="";
        int index=-1;
        for(int i=0;i<=25;i++){
            s += string(a[i] / 2, char(97 + i));
            if((a[i]%2)==1) index=i;
        }
        temp=s;
        if(index!=-1) temp=temp+char(97+index);
        reverse(s.begin(),s.end());
        return temp+s;
    }
};