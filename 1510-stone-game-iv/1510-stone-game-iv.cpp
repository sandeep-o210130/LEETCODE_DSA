class Solution {
public:
    bool findScore(vector<int>&dp,int n)
    {
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++)
        {
            int stone=i*i;
            if(findScore(dp,n-stone)==false) return dp[n]=true;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return findScore(dp,n);
    }
};