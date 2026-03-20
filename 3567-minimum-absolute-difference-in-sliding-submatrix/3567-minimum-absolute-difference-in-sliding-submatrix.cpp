class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n=grid[0].size();
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) sum=1;
            }
        }
        int a=k-1,b=k-1;
        vector<vector<int>> ans(m-k+1,vector<int> (n-k+1,0));
        if(k==1 || sum==0) return ans;
        while((a<m) && (b<n)){
            vector<int> al;
            int p = a-(k-1), q= b-(k-1);
            for(int i=p;i<(p+k);i++){
                for(int j=q;j<(q+k);j++){
                    al.push_back(grid[i][j]);
                }
            }
            sort(al.begin(),al.end());
            int minn = INT_MAX;
            for(int i=0;i<al.size()-1;i++){
                if((al[i+1]!=al[i])) minn = min(minn,abs(al[i+1]-al[i]));
            }
            ans[p][q]=minn;
            b++;
            if(b==n){
                a++;
                b=k-1;
            }
        }
        return ans;
    }
};