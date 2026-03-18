class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int c=0,m = grid.size(),n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=grid[i][j]+grid[i][j-1];
                if(i>0) grid[i][j]=grid[i][j]+grid[i-1][j];
                if(i>0 && j>1) grid[i][j]=grid[i][j]-grid[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]<=k) c++;
            else break;
        }
        for(int i=1;i<m;i++){
            grid[i][0]=grid[i-1][0]+grid[i][0];
            if(grid[i][0]<=k) c++;
            else break;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]<=k) c++;
                else break;
            }
        }
        return c;
    }
};