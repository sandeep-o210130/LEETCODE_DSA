class Solution {
public:
    vector<vector<pair<long long,long long>>> dp;
    vector<vector<bool>> vis;

    pair<long long,long long> anss(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i==m-1 && j==n-1) {
            return {grid[i][j], grid[i][j]};
        }

        if(vis[i][j]) return dp[i][j]; 

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        if(j+1 < n){
            auto right = anss(grid,i,j+1,m,n);

            long long a = grid[i][j] * right.first;
            long long b = grid[i][j] * right.second;

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        if(i+1 < m){
            auto down = anss(grid,i+1,j,m,n);

            long long a = grid[i][j] * down.first;
            long long b = grid[i][j] * down.second;

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        vis[i][j] = true;
        return dp[i][j] = {maxi, mini}; 
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9+7;

        dp.assign(m, vector<pair<long long,long long>>(n));
        vis.assign(m, vector<bool>(n,false));

        auto res = anss(grid,0,0,m,n);

        if(res.first < 0) return -1;
        return res.first % MOD;
    }
};