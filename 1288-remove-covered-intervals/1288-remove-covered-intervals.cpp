class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int c=0,e=0;
        sort(in.begin(),in.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0]<=b[0];
        });
        for(int i=1;i<in.size();i++){
            e = max(e,in[i-1][1]);
            if(e>=in[i][1]) c++;
        }
        return in.size()-c;
    }
};