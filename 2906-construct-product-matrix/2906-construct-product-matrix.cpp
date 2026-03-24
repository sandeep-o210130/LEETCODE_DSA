class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> p(m,vector<int>(n,1)),s(m,vector<int>(n,1)),t(m,vector<int>(n,1));
        int summ=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                p[i][j]=summ;
                summ=(summ*(grid[i][j]%(12345)))%(12345);
            }
        }
        summ=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                s[i][j]=summ;
                summ=(summ*(grid[i][j]%(12345)))%(12345);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                t[i][j]=(p[i][j]*s[i][j])%(12345);
            }
        }
        return t;
    }
};