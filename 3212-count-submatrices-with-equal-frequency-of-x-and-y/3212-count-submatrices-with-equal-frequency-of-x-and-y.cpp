class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<pair<int,int>>> ans(m,vector<pair<int,int>>(n,{0,0}));
        for(int i=0;i<m;i++){
            if (grid[i][0]=='X') ans[i][0].first++;
            else if(grid[i][0]=='Y') ans[i][0].second++;
            for(int j=1;j<n;j++){
                if(grid[i][j]=='X'){
                    ans[i][j].first = ans[i][j-1].first+1;
                    ans[i][j].second=ans[i][j-1].second;
                }
                else if(grid[i][j]=='Y'){
                    ans[i][j].first = ans[i][j-1].first;
                    ans[i][j].second=ans[i][j-1].second+1;
                }
                else{
                    ans[i][j].first = ans[i][j-1].first;
                    ans[i][j].second=ans[i][j-1].second;
                }
                if(i>0){
                    ans[i][j].first = ans[i-1][j].first+ans[i][j].first;
                    ans[i][j].second = ans[i-1][j].second+ans[i][j].second;
                }
                if((i>0) && (j>1)){
                    ans[i][j].first = ans[i][j].first-ans[i-1][j-1].first;
                    ans[i][j].second = ans[i][j].second-ans[i-1][j-1].second;
                }
            }
        }   
        int c=0;
        for(int i=0;i<m;i++){
            if(i>0){
                ans[i][0].first = ans[i-1][0].first+ans[i][0].first;
                ans[i][0].second = ans[i-1][0].second+ans[i][0].second;
            }
            if((ans[i][0].first==ans[i][0].second) && (ans[i][0].first)) c++;
        }
        for(int i=0;i<n;i++){
            if((ans[0][i].first==ans[0][i].second) && (ans[0][i].first)) c++;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if((ans[i][j].first==ans[i][j].second) && (ans[i][j].first)) c++;
            }
        }
        return c;
    }
};