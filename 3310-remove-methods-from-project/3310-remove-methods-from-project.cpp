class Solution {
public:
    void dfs(int k,vector<int>& temp,unordered_map<int, vector<int>>&mpp){
        temp[k]=1;
        if(!mpp[k].empty()){
            for(auto i:mpp[k]){
                if(temp[i]!=1){
                    dfs(i,temp,mpp);
                }
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> mpp;
        bool t=true;
        for(auto i:invocations) mpp[i[0]].push_back(i[1]);
        vector<int> temp(n,0);
        dfs(k,temp,mpp);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(temp[i]==0 && !mpp[i].empty()){
                for(auto j:mpp[i]){
                    if(temp[j]==1){
                        t=false;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!(t&&temp[i])) ans.push_back(i);
        }
        return ans;
    }
};