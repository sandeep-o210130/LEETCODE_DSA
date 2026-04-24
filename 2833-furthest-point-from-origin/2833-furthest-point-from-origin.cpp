class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int c=0,b=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') b++;
            else if(moves[i]=='R') b--;
            else c++;
        }
        return abs(b)+c;
    }
};