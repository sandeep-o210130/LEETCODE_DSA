class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mat(m, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            mat[0][i] = matrix[0][i];
            for(int j=1;j<m;j++){
                if(matrix[j][i] == 0) mat[j][i] = 0;
                else mat[j][i] = mat[j-1][i] + 1;
            }
        }   

        int anss = 0;

        for(int i=0;i<m;i++){
            sort(mat[i].begin(), mat[i].end(), greater<int>());

            int height = mat[i][0];
            anss = max(anss, height);

            for(int j=1;j<n;j++){
                height = min(height, mat[i][j]);
                anss = max(anss, (j+1) * height);
            }
        }

        return anss;
    }
};