class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        int bitCount[31] = {};

        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if ((num >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long val = 0;

            for (int b = 0; b < 31; b++) {
                if (bitCount[b] > i) {
                    val |= (1LL << b);
                }
            }

            ans = (ans + val * val % MOD) % MOD;
        }

        return ans;
    }
};