class Solution {
public:

    int x,y;
    vector<vector<vector<int>>>dp;

    int f(vector<vector<int>>& grid,int a,int b,int cost,int k){

        if(a>=x || b>=y) return -1;

        int newCost=cost+(grid[a][b]!=0);

        if(newCost>k) return -1;

        if(a==x-1 && b==y-1) return grid[a][b];

        if(dp[a][b][newCost]!=INT_MIN)  return dp[a][b][newCost];

        int right=f(grid,a,b+1,newCost,k);
        int down=f(grid,a+1,b,newCost,k);
        int best=max(right,down);

        if(best==-1) return dp[a][b][newCost]=-1; 

        return dp[a][b][newCost]=grid[a][b]+best;

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {

        x=grid.size();
        y=grid[0].size();

        dp.assign(x,vector<vector<int>>(y,vector<int>(k+1,INT_MIN)));

        return f(grid,0,0,0,k);

    }
};