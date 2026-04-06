class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>,int> mpp;
        for(auto i:obstacles) mpp[{i[0],i[1]}]++;

        int x=0,y=0,dir=0;
        int ans=0;

        for(int i=0;i<commands.size();i++){

            if(commands[i]==-1){
                dir=(dir+1)%4;
                continue;
            }
            else if(commands[i]==-2){
                dir=(dir+3)%4;
                continue;
            }

            int j=0;
            int steps = commands[i];

            if(dir==0){
                while(j < steps && mpp.find({x,y+1})==mpp.end()){
                    y++; j++;
                }
            }
            else if(dir==1){
                while(j < steps && mpp.find({x+1,y})==mpp.end()){
                    x++; j++;
                }
            }
            else if(dir==2){
                while(j < steps && mpp.find({x,y-1})==mpp.end()){
                    y--; j++;
                }
            }
            else if(dir==3){
                while(j < steps && mpp.find({x-1,y})==mpp.end()){
                    x--; j++;
                }
            }

            ans = max(ans, x*x + y*y);
        }

        return ans;
    }
};