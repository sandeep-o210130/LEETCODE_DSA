class Solution {
public:
    bool judgeCircle(string moves) {
        int c=0,c1=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') c++;
            else if(moves[i]=='U') c1++;
            else if(moves[i]=='D') c1--;
            else c--;
        }
        return (c==0) && (c1==0);
    }
};