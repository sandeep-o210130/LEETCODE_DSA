class Solution {
public:
    void uni(int a,int b,vector<int>& p){
        int pa=find(a,p);
        int pb=find(b,p);
        if(pa!=pb){
            p[pb]=pa;
        }
    }
    int find(int x, vector<int>& p){
        if(p[x]!=x)
            p[x]=find(p[x], p);
        return p[x];
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> d(n);
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<n;i++) d[i]=i;
        for(int i=1;i<n;i++){
            if(abs(nums[i-1]-nums[i])<=maxDiff) uni(i,i-1,d);
        }
        for(int i=0;i<queries.size();i++){
            int i1  = find(queries[i][0],d),i2 = find(queries[i][1],d);
            if(i1==i2) ans[i]=true;
        }
        return ans;
    }
};