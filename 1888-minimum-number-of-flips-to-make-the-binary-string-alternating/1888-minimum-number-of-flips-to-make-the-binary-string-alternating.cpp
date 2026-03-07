class Solution {
public:
    int minFlips(string s) {
        int o0=0,o1=0,e0=0,e1=0,n=s.size();
        for(int i=0;i<n;i++){
            if((i+1)%2){
                (s[i]=='0')?o0++:o1++;
            }
            else (s[i]=='0')?e0++:e1++;
        }
        int ans = min(e0+o1,o0+e1);
        if(ans==0 || !(n%2)) return ans;

        for(int i=0;i<n;i++){
            swap(o1,e1);
            swap(o0,e0);
            if(s[i]=='0'){
                o0++;
                e0--;
            }
            else{
                o1++;
                e1--;
            }
            ans = min(ans,min(e0+o1,o0+e1));
        }
        return ans;
    }
};