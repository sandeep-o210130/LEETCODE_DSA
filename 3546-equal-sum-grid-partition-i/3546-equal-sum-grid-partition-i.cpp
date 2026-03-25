class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<long long> h(m,0),v(n,0);
        for(int i=0;i<m;i++){
            long long sum=0;
            for(int j=0;j<n;j++) sum+=grid[i][j];
            h[i]=sum;
            if(i>0) h[i]=h[i]+h[i-1];
        }
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++) sum+=grid[j][i];
            v[i]=sum;
            if(i>0) v[i]=v[i]+v[i-1];
        }
        for(int i=0;i<m-1;i++){
            if(h[i]==(h[m-1]-h[i])) return true;
        }
        for(int i=0;i<n-1;i++){
            if(v[i]==(v[n-1]-v[i])) return true;
        }
        return false;
    }
};