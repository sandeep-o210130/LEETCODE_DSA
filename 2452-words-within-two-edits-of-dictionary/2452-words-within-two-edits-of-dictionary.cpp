class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        unordered_map<string,int> mpp;
        vector<string> ans;
        int n = queries[0].size();
        for(auto i:dictionary) mpp[i]=1;
        int c=0;
        for(int i=0;i<queries.size();i++){
            if(mpp.find(queries[i])!=mpp.end()) {
                ans.push_back(queries[i]);
                continue;
            }
            for(auto j:dictionary){
                int c1=0;
                for(int k=0;k<n;k++){
                    if(queries[i][k]!=j[k]) c1++;
                    if(c1>2) break;
                }
                if(c1<=2){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};