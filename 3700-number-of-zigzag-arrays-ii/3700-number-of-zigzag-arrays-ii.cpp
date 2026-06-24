class Solution {
public:
    static const int MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();

        Matrix C(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {

                if (A[i][k] == 0) continue;

                for (int j = 0; j < sz; j++) {

                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] +
                         A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {

        int sz = base.size();

        Matrix result(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++)
            result[i][i] = 1;

        while (exp) {

            if (exp & 1)
                result = multiply(result, base);

            base = multiply(base, base);

            exp >>= 1;
        }

        return result;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        int states = 2 * m;

        auto id = [&](int val, int dir) {
            return dir * m + val;
        };

        Matrix T(states,
                 vector<long long>(states, 0));

        for (int x = 0; x < m; x++) {

            for (int y = 0; y < x; y++) {
                T[id(y,0)][id(x,1)]++;
            }

            for (int y = x + 1; y < m; y++) {
                T[id(y,1)][id(x,0)]++;
            }
        }

        vector<long long> start(states, 0);

        for (int a = 0; a < m; a++) {

            for (int b = 0; b < m; b++) {

                if (a == b) continue;

                if (a < b)
                    start[id(b,1)]++;
                else
                    start[id(b,0)]++;
            }
        }

        Matrix P = power(T, n - 2);

        long long ans = 0;

        for (int i = 0; i < states; i++) {

            long long cur = 0;

            for (int j = 0; j < states; j++) {
                cur = (cur + P[i][j] * start[j]) % MOD;
            }

            ans = (ans + cur) % MOD;
        }

        return (int)ans;
    }
};