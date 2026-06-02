class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX,n = landStartTime.size(),m = waterStartTime.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int maxx = landStartTime[i]+landDuration[i]+waterDuration[j];
                if(waterStartTime[j]>(landStartTime[i]+landDuration[i])){
                    maxx = maxx+waterStartTime[j]-(landStartTime[i]+landDuration[i]);
                }
                ans = min(ans,maxx);
            }
        }  

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int maxx = waterStartTime[i]+waterDuration[i]+landDuration[j];
                if(landStartTime[j]>(waterStartTime[i]+waterDuration[i])){
                    maxx = maxx+landStartTime[j]-(waterStartTime[i]+waterDuration[i]);
                }
                ans = min(ans,maxx);
            }
        } 
        return ans;
    }
};