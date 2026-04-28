class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem = grid[0][0]%x;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((grid[i][j]%x)!=rem) return -1;
            }
        }
        vector<int> temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        if(temp.size()==1) return 0;
        sort(temp.begin(),temp.end());
        for(int i=1;i<temp.size();i++) temp[i]=temp[i]+temp[i-1];
        int ans=0;
        int m = temp.size()/2;
        ans = ans+ (m*(temp[m]-temp[m-1])-(temp[m-1]))/x;
        ans = ans+((temp[temp.size()-1]-temp[m])-(temp.size()-m-1)*(temp[m]-temp[m-1]))/x;
        return ans;
    }
};