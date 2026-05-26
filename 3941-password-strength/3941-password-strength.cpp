class Solution {
public:
    int passwordStrength(string password) {
        int c=0;
        unordered_map<int,int> mpp;
        for(auto i:password){
            if(i>=65 && i<=90){
                if(mpp.find(i)==mpp.end()) c+=2;
                mpp[i]++;
            }
            else if(i>=97 && i<=122){
                if(mpp.find(i)==mpp.end()) c+=1;
                mpp[i]++;
            }
            else if(i>=48 && i<=57){
                if(mpp.find(i)==mpp.end()) c+=3;
                mpp[i]++;
            }
            else if(i=='!' || i=='@' || i=='#' || i=='$'){
                if(mpp.find(i)==mpp.end()) c+=5;
                mpp[i]++;
            }
        }
        return c;
    }
};