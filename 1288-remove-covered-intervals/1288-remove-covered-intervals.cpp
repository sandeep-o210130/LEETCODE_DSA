class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int c=0;
        for(int i=0;i<in.size();i++){
            for(int j=0;j<in.size();j++){
                if(i!=j){
                    if(in[i][0]>=in[j][0] && in[i][1]<=in[j][1]){
                        c++;
                        break;
                    }
                }
            }
        }
        return in.size()-c;
    }
};