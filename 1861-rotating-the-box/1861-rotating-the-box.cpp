class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();
        vector<vector<char>> b(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                b[j][i]=boxGrid[i][j];
            }
        }
        for(int i=0;i<n;i++) reverse(b[i].begin(),b[i].end());
        for(int i=0;i<m;i++){
            int j=0;
            while(j<n){
                if(b[j][i]=='.'){
                    int k=j-1;
                    while(k>=0 && b[k][i]!='*'){
                        swap(b[k+1][i],b[k][i]);
                        k--;
                    }
                }
                j++;
            }
        }
        return b;
    }
};