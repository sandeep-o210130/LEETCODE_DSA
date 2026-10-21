class Solution {
public:
    static int minOperations(string& s) {
        const int n=s.size();
        if(n==2) return 0-(s[0]>s[1]);
        if (is_sorted(s.begin(), s.end())) return 0;
        auto [mn, mx]=minmax_element(s.begin()+1, s.end()-1);
        if ((s[0]<=*mn && s[0]<=s.back()) || (s.back()>=*mx && s.back()>=s[0])) {

            return 1;
        }
        if (*mx<s[0] && *mn>s.back()) return 3;
        return 2;
    }
};