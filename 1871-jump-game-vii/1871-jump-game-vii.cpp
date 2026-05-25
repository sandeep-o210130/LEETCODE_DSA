class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int n = s.size();
        vector<int> v(n,0);
        q.push(0);
        v[0]=1;
        int far=1;
        while(!q.empty()){
            int ele = q.front();
            if(ele==(s.size()-1)) return true;
            q.pop();
            int S=max(far,ele+minJump),e=min(ele+maxJump,n-1);
            for(int i=S;i<=e;i++){
                if(s[i]=='0' && !v[i]){
                    q.push(i);
                    v[i]=1;
                }
            }
            far=e+1;
        }
        return false;
    }
};