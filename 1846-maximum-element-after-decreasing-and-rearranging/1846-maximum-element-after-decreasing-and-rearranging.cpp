class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int c=0,l=0;
        vector<int> vis(arr.size()+1,0);
        for(auto i:arr){
            if(i<=arr.size()){
                vis[i]++;
            }
        }
        for(int i=1;i<vis.size();i++){
            if(vis[i]==0) l++;
            else{
                if((vis[i]-1)>l){
                    c=c+vis[i]-1-l;
                    l=0;
                }
            }
        }
        return arr.size()-c;
    }
};