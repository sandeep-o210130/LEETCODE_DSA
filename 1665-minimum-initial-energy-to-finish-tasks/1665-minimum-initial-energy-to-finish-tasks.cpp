class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int>&a,const vector<int>&b){
            return (b[1]-b[0])<(a[1]-a[0]);
        });
        int anss = tasks[0][1],temp=0;
        temp = tasks[0][1]-tasks[0][0];
        for(int i=1;i<tasks.size();i++){
            if(tasks[i][1]<=temp)
                temp=temp-tasks[i][0];
            else{
                anss = anss+tasks[i][1]-temp;
                temp = tasks[i][1]-tasks[i][0];
            }
        }
        return anss;
    }
};