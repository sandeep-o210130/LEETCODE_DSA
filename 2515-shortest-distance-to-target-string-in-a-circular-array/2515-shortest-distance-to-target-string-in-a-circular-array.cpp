class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int pos1=-1,pos2=-1,n=words.size(),c=0;
        for(int i=0;i<words.size();i++){
            if(words[(i+startIndex)%n]==target){
                pos1=c;
                break;
            }
            c++;
        }
        c=0;
        for(int i=0;i<words.size();i++){
            if(words[(startIndex-i+n)%n]==target){
                pos2=c;
                break;
            }
            c++;
        }
        if(pos1==-1 && pos2==-1) return -1;
        return min(pos1,pos2);
    }
};