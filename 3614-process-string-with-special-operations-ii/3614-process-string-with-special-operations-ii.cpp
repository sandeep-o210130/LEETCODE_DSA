class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        // Forward: compute lengths
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                len[i + 1] = len[i] + 1;
            }
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (c == '#') {
                len[i + 1] = len[i] * 2;
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        // Backward: find which original character lands at index k
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                if (k == len[i])
                    return c;
            }
            else if (c == '#') {
                long long L = len[i];

                if (k >= L)
                    k -= L;
            }
            else if (c == '%') {
                long long L = len[i];

                if (L > 0)
                    k = L - 1 - k;
            }
            else { // '*'
                // Forward removed the last char.
                // Backward, indices before that stay unchanged.
            }
        }

        return '.';
    }
};