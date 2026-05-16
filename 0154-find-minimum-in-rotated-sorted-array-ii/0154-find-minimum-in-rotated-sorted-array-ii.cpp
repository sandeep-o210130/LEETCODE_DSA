class Solution {
public:
    int findMin(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(auto i:nums){
            if(mpp.find(i)!=mpp.end()) continue;
            mpp[i]=1;
            ans.push_back(i);
        }
        int beg=0,end=ans.size()-1;
        int minn = ans[beg];
        while(beg<=end){
            int mid = beg+((end-beg)/2);
            if(ans[0]<=ans[mid]){
                beg = mid+1;
            }
            else{
                minn = min(minn,ans[mid]);
                end=mid-1;
            }
        }
        return minn;
    }
};