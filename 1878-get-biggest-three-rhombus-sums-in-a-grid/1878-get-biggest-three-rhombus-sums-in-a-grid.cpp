class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dr(m,vector<int> (n,0)),dl(m,vector<int> (n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dr[i][j] = grid[i][j];
                if(i > 0 && j > 0)
                    dr[i][j] += dr[i-1][j-1];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = n-1; j >= 0; j--){
                dl[i][j] = grid[i][j];
                if(i > 0 && j + 1 < n)
                    dl[i][j] += dl[i-1][j+1];
            }
        }
        priority_queue<int,vector<int>, less<int>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int d=0;;d++){
                    if((i+(2*d)<m) && (j+d<n) && ((j-d)>=0)){
                        if(d==0){
                            pq.push(grid[i][j]);
                            continue;
                        }
                       int sum =
                            dr[i+d][j+d] - dr[i][j] +
                            dl[i+d][j-d] - dl[i][j] +
                            dr[i+2*d][j] - dr[i+d][j-d] +
                            dl[i+2*d][j] - dl[i+d][j+d] +
                            grid[i][j] - grid[i+2*d][j];
                        pq.push(sum);
                    }
                    else break;
                }
            }
        }
        vector<int> ans;
        int i=0;
        while((i<3) && (!pq.empty())){
            int a = pq.top();
            pq.pop();
            while((!pq.empty()) && (a==pq.top())){
                pq.pop();
            }
            ans.push_back(a);
            i++;
        }
        return ans;
    }
};