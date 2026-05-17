class Solution {
public:
    bool anss(vector<int>& arr,int start,vector<int>& vis){
        if(arr[start]==0) return true;
        vis[start]=1;
        bool temp = false;
        if(((start-arr[start])>=0) && (vis[start-arr[start]]==0)){
            if(anss(arr,start-arr[start],vis)) return true;
        }
        if(((start+arr[start])<arr.size()) && (vis[start+arr[start]]==0)){
            if(anss(arr,start+arr[start],vis)) return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(),0);
        return anss(arr,start,vis);
    }
};