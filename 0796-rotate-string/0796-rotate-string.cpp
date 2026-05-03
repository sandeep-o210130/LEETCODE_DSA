class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if((s+s).find(goal)!=-1) return true;
        return false;
    }
};