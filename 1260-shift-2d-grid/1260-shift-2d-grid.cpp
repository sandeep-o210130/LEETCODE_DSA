class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        for(int i1=0;i1<k;i1++){
            vector<vector<int>> temp(m,vector<int>(n));
            for(int i=0;i<m;i++){
                for(int j=1;j<n;j++){
                    temp[i][j]=grid[i][j-1];
                }
            }
            temp[0][0]=grid[m-1][n-1];
            for(int i=1;i<m;i++) temp[i][0]=grid[i-1][n-1];
            grid=temp;
        }
        return grid;
    }
};