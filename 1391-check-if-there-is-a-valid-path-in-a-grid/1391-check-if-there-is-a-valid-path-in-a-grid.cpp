class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // allowed moves for each type
        vector<vector<pair<int,int>>> dir(7);

        dir[1] = {{0,-1},{0,1}};   // left right
        dir[2] = {{-1,0},{1,0}};   // up down
        dir[3] = {{0,-1},{1,0}};   // left down
        dir[4] = {{0,1},{1,0}};    // right down
        dir[5] = {{0,-1},{-1,0}};  // left up
        dir[6] = {{0,1},{-1,0}};   // right up

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if(r==m-1 && c==n-1)
                return true;

            // try all moves from current cell
            for(auto [dr,dc] : dir[grid[r][c]]){
                int nr = r + dr;
                int nc = c + dc;

                if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc])
                    continue;

                // check reverse connection
                for(auto [bdr,bdc] : dir[grid[nr][nc]]){
                    if(nr + bdr == r && nc + bdc == c){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return false;
    }
};