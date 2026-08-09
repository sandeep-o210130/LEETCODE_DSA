class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int> suf(n+1,0);
        for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]+piles[i];
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        function<int(int,int)> solve=[&](int i,int m){
            if(i==n) return 0;
            if(dp[i][m]!=-1) return dp[i][m];
            int ans=0;
            for(int x=1;x<=2*m&&i+x<=n;x++)
                ans=max(ans,suf[i]-solve(i+x,max(m,x)));
            return dp[i][m]=ans;
        };
        
        return solve(0,1);
    }
};