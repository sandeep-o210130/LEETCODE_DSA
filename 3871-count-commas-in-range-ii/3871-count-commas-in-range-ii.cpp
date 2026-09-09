class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long base = 1000;
        int commas = 1;

        while(base <= n){
            long long end = base * 1000 - 1;
            long long count = min(n, end) - base + 1;

            ans += count * commas;
            
            base *= 1000;
            commas++;
        }

        return ans;
    }
};