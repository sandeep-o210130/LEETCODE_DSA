class Solution {
public:
    string processStr(string s) {
        int i1=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(!ans.empty()){
                if(s[i]=='*'){
                    if(i1) ans.erase(ans.begin());
                    else ans.pop_back();
                }
                else if(s[i]=='#'){
                    cout<<ans<<endl;
                    ans+=ans;
                }
                else if(s[i]=='%'){
                    i1=i1+1;
                    i1=i1%2;
                }
            }
            if(s[i]>='a' && s[i]<='z'){
                if(!i1) ans+=s[i];
                else ans=s[i]+ans;
            }
            cout<<ans<<endl;
        }   
        if(i1) reverse(ans.begin(),ans.end());
        return ans;
    }
};