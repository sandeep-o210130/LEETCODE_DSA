class Solution {
public:
    
    static const int MOD = 1e9+7;
    int dp[201][201][201][2];

    int fun(int zero,int one,int limit,int i,int j,int l,int prev){

        if(l>limit || i>zero || j>one) return 0;

        if(i==zero && j==one) return 1;

        if(dp[i][j][l][prev]!=-1) return dp[i][j][l][prev];

        long long ans=0;

        if(prev==0){
            ans+=fun(zero,one,limit,i+1,j,l+1,0);
            ans+=fun(zero,one,limit,i,j+1,1,1);
        }
        else{
            ans+=fun(zero,one,limit,i,j+1,l+1,1);
            ans+=fun(zero,one,limit,i+1,j,1,0);
        }

        return dp[i][j][l][prev]=ans%MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(dp,-1,sizeof(dp));

        long long ans=0;

        ans+=fun(zero,one,limit,1,0,1,0);
        ans+=fun(zero,one,limit,0,1,1,1);

        return ans%MOD;
    }
};