class Solution {
public:
    int maxDepth(string s) {
        int sol = 0, curr = 0;
        for(auto it : s){
            if(it == '('){
                curr++;
                sol = max(curr, sol);
            }else if(it == ')'){
                curr--;
            }
        }
        return sol;
    }
};