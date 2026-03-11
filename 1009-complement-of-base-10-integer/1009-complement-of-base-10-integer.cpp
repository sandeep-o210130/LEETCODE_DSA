class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        long long b = log2(n)+1;
        long long a = pow(2,b)-1;
        return a-n;
    }
};