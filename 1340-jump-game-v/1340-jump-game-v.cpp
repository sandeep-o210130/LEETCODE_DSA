class Solution {
public:
    int solve(vector<int>& arr,int d,int i,vector<int>& vis,vector<int>& dp){
        int big=-1;
        if(dp[i]!=0) return dp[i];
        for(int j=i-1;j>=i-d;j--){
            int ans=0;
            if(j>=0) big = max(big,arr[j]);
            if(j>=0 && arr[i]>big){
                if(vis[j]==0){
                    vis[j]=1;
                    ans = 1+solve(arr,d,j,vis,dp);
                    vis[j]=0;
                }
            }
            else break;
            dp[i] = max(dp[i],ans);
        }
        big=-1;
        for(int j=i+1;j<=i+d;j++){
            int ans=0;
            if(j<arr.size()) big = max(big,arr[j]);
            if(j<arr.size() && arr[i]>big){
                if(vis[j]==0){
                    vis[j]=1;
                    ans = 1+solve(arr,d,j,vis,dp);
                    vis[j]=0;
                }
            }
            else break;
            dp[i] = max(dp[i],ans);
        }
        return dp[i];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int>vis(n,0);
        int ans=0;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            ans = max(ans,solve(arr,d,i,vis,dp));
        }
        return ans+1;
    }
};