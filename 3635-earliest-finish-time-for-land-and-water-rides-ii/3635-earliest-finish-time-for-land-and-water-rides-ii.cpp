class Solution {
public:
    int anss(vector<int>& a1, vector<int>& a2, vector<int>& b1, vector<int>& b2){
        int fin=INT_MAX,fin2 = INT_MAX;
        for(int i=0;i<a1.size();i++) fin = min(fin,a1[i]+a2[i]);
        for(int i=0;i<b1.size();i++) fin2 = min(fin2,max(fin,b1[i])+b2[i]);
        return fin2;
    }
    int earliestFinishTime(vector<int>& a1, vector<int>& a2, vector<int>& b1, vector<int>& b2) {
        return min(anss(a1,a2,b1,b2),anss(b1,b2,a1,a2));
    }
};