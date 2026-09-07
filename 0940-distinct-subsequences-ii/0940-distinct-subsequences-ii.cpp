class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        long long endsWith[26] = {0};
        long long total = 0; 
        for (char ch : s) {
            int idx = ch - 'a';
            
            long long newForCh = (total + 1) % MOD;
            
            total = (total - endsWith[idx] + newForCh) % MOD;
            if (total < 0) {
                total += MOD;
            }
            
            endsWith[idx] = newForCh;
        }
        
        return total;
    }
};