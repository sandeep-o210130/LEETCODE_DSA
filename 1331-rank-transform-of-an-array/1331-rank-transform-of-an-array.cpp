class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<int> temp=arr,c;
        unordered_map<int,int> mpp;
        sort(temp.begin(),temp.end());
        int c1=1;
        mpp[temp[0]]=c1;
        for(int i=1;i<temp.size();i++){
            if(temp[i]!=temp[i-1]) c1++;
            mpp[temp[i]]=c1;
        }
        for(int i=0;i<arr.size();i++) c.push_back(mpp[arr[i]]);
        return c;
    }
};