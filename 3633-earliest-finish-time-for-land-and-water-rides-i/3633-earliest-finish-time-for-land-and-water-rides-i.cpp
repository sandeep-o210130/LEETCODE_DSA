class Solution {
public:
    int anss(vector<int>& a1,vector<int>& a2, vector<int>& b1,vector<int>& b2){
        int minn = INT_MAX,minn2 = INT_MAX;
        for(int i=0;i<a1.size();i++){
            minn = min(minn,a1[i]+a2[i]);
        }
        for(int i=0;i<b1.size();i++){
            minn2 = min(minn2,max(minn,b1[i])+b2[i]);
        }
        return minn2;
    }
    int earliestFinishTime(vector<int>& a1, vector<int>& a2, vector<int>& b1, vector<int>& b2) {
        int ans = INT_MAX,n = a1.size(),m = b1.size();  
        return min(anss(a1,a2,b1,b2),anss(b1,b2,a1,a2));
    }
};