const int N=1000;
char st[N];
int top;
class Solution {
public:
    string smallestSubsequence(string& s) {
        int freq[26]={0};
        for(char c: s) freq[c-'a']++;
        top=-1;
        bitset<26> seen;
        for(char c: s){
            const int idx=c-'a';
            freq[idx]--;
            if (seen[idx]) continue;
            while(top>-1 && st[top]>c && freq[st[top]-'a']>0){
                seen[st[top--]-'a']=0;
            }
            st[++top]=c;
            seen[idx]=1;
        }
        return string(st, st+top+1);
    }
};