class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis,
             int i, int j, int pi, int pj) {
        
        vis[i][j] = true;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                grid[ni][nj] == grid[i][j]) {
                
                if (!vis[ni][nj]) {
                    if (dfs(grid, vis, ni, nj, i, j)) return true;
                }
                
                else if (!(ni == pi && nj == pj)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, vis, i, j, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};