class Solution {
public:
    int m, n;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(vector<vector<int>>& grid,
             vector<vector<vector<int>>>& dp,
             vector<vector<int>>& vis,
             int i, int j, int health) {

        health -= grid[i][j];

        if (health <= 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return true;

        if (dp[i][j][health] != -1)
            return dp[i][j][health];

        vis[i][j] = 1;

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n &&
                !vis[ni][nj]) {

                if (dfs(grid, dp, vis, ni, nj, health)) {
                    vis[i][j] = 0;
                    return dp[i][j][health] = true;
                }
            }
        }

        vis[i][j] = 0;
        return dp[i][j][health] = false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(health + 1, -1))
        );

        vector<vector<int>> vis(m, vector<int>(n, 0));

        return dfs(grid, dp, vis, 0, 0, health);
    }
};