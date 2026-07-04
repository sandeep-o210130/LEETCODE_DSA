class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> mpp;
        for(auto i:roads){
            mpp[i[0]].push_back({i[1],i[2]});
            mpp[i[1]].push_back({i[0],i[2]});
        }
        int minn = INT_MAX;
        queue<int> q;
        vector<int> vis(n+1,0);
        q.push(1);
        vis[1]=1;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto [i,j]:mpp[ele]){
                minn = min(minn,j);
                if(!vis[i]) q.push(i);
                vis[i]=1;
            }
        }
        return minn;
    }
};