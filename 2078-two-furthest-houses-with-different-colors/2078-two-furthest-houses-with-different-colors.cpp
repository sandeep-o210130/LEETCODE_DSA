class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxx=INT_MIN,n=colors.size();
        for(int i=n-1;i>=1;i--){
            if(colors[i]!=colors[0]){
                maxx = i-0;
                break;
            }
        }
        for(int i=0;i<n-1;i++){
            if(colors[i]!=colors[n-1]){
                maxx = max(maxx,n-1-i);
                break;
            }
        }
        return maxx;
    }
};