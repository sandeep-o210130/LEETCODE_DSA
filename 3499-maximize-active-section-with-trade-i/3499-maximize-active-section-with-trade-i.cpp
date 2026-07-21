class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int c=0,i=0,prev=0,curr=0,next=0,k=0,l=1,maxx=0;
        for(auto i1:s) if(i1=='1') c++;
        for(;i<s.size();i++) if(s[i]=='0') break;
        for(;i<s.size();i++) {
            if(s[i]!='1') prev++;
            else break;
        }
        i++;
        for(;i<s.size();i++){
            if(s[i]!=s[i-1]){
                if(k==0) curr=l;
                else{
                    next=l;
                    maxx=max(maxx,next+prev);
                    prev=next;
                }
                k=(k+1)%2;
                l=1;
            }
            else l++;
        }
        if(k==1) maxx=max(maxx,l+prev);
        return c+maxx;
    }
};