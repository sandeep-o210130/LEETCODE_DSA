class Solution {
public:
    int mm;
    int anss(int i,unordered_map<int,vector<int>> &mpp1,vector<int> &temp,int c){
        for(auto j:mpp1[i]){
            temp[i]=1;
            if(temp[j]!=1) mm = max(mm,anss(j,mpp1,temp,c+1));
            temp[i]=0;
        }
        return c;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size(),a=1;
        unordered_map<int,vector<int>> mpp1;
        for(auto i:edges){
            mpp1[i[0]].push_back(i[1]);
            mpp1[i[1]].push_back(i[0]);
        }
        vector<int> temp(n+2,0);
        mm=0;
        anss(1,mpp1,temp,0);
        cout<<mm<<endl;
        for(int i=0;i<mm-1;i++){
            a=(a*2)%(1000000007);
        }
        return a;
    }
};