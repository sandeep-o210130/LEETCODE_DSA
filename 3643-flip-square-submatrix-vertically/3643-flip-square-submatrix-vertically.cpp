class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=y;i<y+k;i++){
            int j=x,l=x+k-1;
            while(j<l){
                swap(grid[j][i],grid[l][i]);
                j++;
                l--;
            }
        }
        return grid;
    }
};