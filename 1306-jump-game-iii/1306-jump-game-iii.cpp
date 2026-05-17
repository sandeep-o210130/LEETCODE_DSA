class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(),0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            if(!arr[ele]) return true;
            if((ele+arr[ele])<arr.size() && (!vis[ele+arr[ele]])){
                q.push(ele+arr[ele]);
                vis[ele+arr[ele]]=1;
            }
           if((ele-arr[ele])>=0 && (!vis[ele-arr[ele]])){
                q.push(ele-arr[ele]);
                vis[ele-arr[ele]]=1;
           } 
        }
        return false;
    }
};