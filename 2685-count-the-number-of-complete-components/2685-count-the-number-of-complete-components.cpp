class Solution {
public:
    int minn=INT_MAX,c1=0;
    void dfs(unordered_map<int,vector<int>>& mpp,vector<int>& vis,int j){
        vis[j]=1;
        for(int i=0;i<mpp[j].size();i++){
            if(!vis[mpp[j][i]]) dfs(mpp,vis,mpp[j][i]);
        }
        c1++;
        minn = min(minn,(int) mpp[j].size());
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> mpp;
        for(auto i:edges){
            mpp[i[0]].push_back(i[1]);
            mpp[i[1]].push_back(i[0]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(mpp,vis,i);
            if((c1==1) || (c1==(minn+1))) c++;
            c1=0;
            minn=INT_MAX;
        }
        return c++;
    }
};