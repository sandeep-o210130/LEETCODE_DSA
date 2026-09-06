class Solution {
public:
    int c=0;
    int fun(const string &s,const string &t,int i,int j,vector<vector<int>> &dp){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int t1=0,nt=0;
        if(s[i]==t[j]) t1 = fun(s,t,i+1,j+1,dp);
        nt = fun(s,t,i+1,j,dp);
        return dp[i][j] = t1+nt;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return fun(s,t,0,0,dp);
    }
};