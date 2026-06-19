class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxx=0,c=0;
        for(int i=0;i<gain.size();i++){
            c=c+gain[i];
            if(c>maxx) maxx=c;
        }
        return maxx;
    }
};