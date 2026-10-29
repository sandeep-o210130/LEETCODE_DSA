bitset<1024> dp[1000];
constexpr auto zero=bitset<1024>();
class Solution {
public:
    static int minCost(vector<vector<int>>& grid) {
        const int r=grid.size(), c=grid[0].size(), N=r*c;
        fill_n(dp, N, zero);
        // 0th row
        int xorSum=0;
        for(int j=0; j<c; j++){
            xorSum^=grid[0][j];
            dp[j][xorSum]=1;
        }
        xorSum=grid[0][0];
        for(int i=1; i<r; i++){
            // 0th col
            xorSum^=grid[i][0];
            int id=i*c;
            dp[id][xorSum]=1;
            for(int j=1; j<c; j++){
                id++;
                bitset<1024> prv=dp[id-1]|dp[id-c];
                for(int b=prv._Find_first(); b<1024; b=prv._Find_next(b))
                    dp[id][b^grid[i][j]]=1;
            }
        }
        return dp[N-1]._Find_first();
    }
};