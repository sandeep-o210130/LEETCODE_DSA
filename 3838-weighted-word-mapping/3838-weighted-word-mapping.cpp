class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto i:words){
            int val=0;
            for(auto j:i) val=(val+weights[j-'a'])%26;
            ans=ans+ (char) (97+25-val);
        }
        return ans;
    }
};