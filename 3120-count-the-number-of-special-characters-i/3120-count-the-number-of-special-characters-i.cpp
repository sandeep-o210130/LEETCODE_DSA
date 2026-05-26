class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int>mpp;
        int c=0;
        for(auto i:word){
            if(i>=65 && i<=90){
                if(mpp.find(i-'A'+33)!=mpp.end()){
                    if(mpp.find(i-'A')==mpp.end()) c++;
                }
                mpp[i-'A']++;
            }
            else{
                if(mpp.find(i-'a')!=mpp.end()){
                    if(mpp.find(i-'a'+33)==mpp.end()) c++;
                }
                mpp[i-'a'+33]++;
            }
        }
        return c;
    }
};