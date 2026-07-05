class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dpSum, dpCnt;
    int n;

    // returns {maxSum, count}. count == 0 means unreachable.
    pair<long long,long long> solve(vector<string>& board, int i, int j) {
        if (i == 0 && j == 0) return {0, 1};
        if (dpCnt[i][j] != -1) return {dpSum[i][j], dpCnt[i][j]};

        long long bestSum = -1, cnt = 0;

        // three moves toward E: left, up, up-left diagonal
        if (j-1 >= 0 && board[i][j-1] != 'X') {
            auto [s, c] = solve(board, i, j-1);
            if (c > 0) {
                if (s > bestSum) { bestSum = s; cnt = c; }
                else if (s == bestSum) cnt = (cnt + c) % MOD;
            }
        }
        if (i-1 >= 0 && board[i-1][j] != 'X') {
            auto [s, c] = solve(board, i-1, j);
            if (c > 0) {
                if (s > bestSum) { bestSum = s; cnt = c; }
                else if (s == bestSum) cnt = (cnt + c) % MOD;
            }
        }
        if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] != 'X') {
            auto [s, c] = solve(board, i-1, j-1);
            if (c > 0) {
                if (s > bestSum) { bestSum = s; cnt = c; }
                else if (s == bestSum) cnt = (cnt + c) % MOD;
            }
        }

        if (cnt == 0) {
            dpSum[i][j] = -1;
            dpCnt[i][j] = 0; // memoized as unreachable
        } else {
            dpSum[i][j] = bestSum + (board[i][j] - '0');
            dpCnt[i][j] = cnt;
        }
        return {dpSum[i][j], dpCnt[i][j]};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        board[n-1][n-1] = '0';
        board[0][0] = '0';

        dpSum.assign(n, vector<long long>(n, -1));
        dpCnt.assign(n, vector<long long>(n, -1)); // -1 = not computed yet

        auto [sum, cnt] = solve(board, n-1, n-1);
        if (cnt == 0) return {0, 0};
        return {(int)sum, (int)cnt};
    }
};