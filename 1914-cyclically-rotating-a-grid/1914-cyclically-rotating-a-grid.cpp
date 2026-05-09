class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        int layers = min(m/2,n/2);
        for(int layer=0;layer<layers;layer++){
            int top = layer,bottom = m-1-layer,left = layer, right = n-1-layer;
            vector<int> temp;
            for(int i=left;i<=right;i++) temp.push_back(grid[top][i]);
            for(int i=top+1;i<bottom;i++) temp.push_back(grid[i][right]);
            for(int i=right;i>left;i--) temp.push_back(grid[bottom][i]);
            for(int i=bottom;i>top;i--) temp.push_back(grid[i][left]);
            int s = temp.size();
            int kk = k%s;
            for(int i=left;i<=right;i++){
                grid[top][i]=temp[kk];
                kk = (kk+1)%s;
            }
            for(int i=top+1;i<bottom;i++){
                grid[i][right]=temp[kk];
                kk = (kk+1)%s;
            }
            for(int i=right;i>left;i--){
                grid[bottom][i]=temp[kk];
                kk = (kk+1)%s;
            }
            for(int i=bottom;i>top;i--){
                grid[i][left]=temp[kk];
                kk = (kk+1)%s;
            }
        }   
        return grid;
    }
};