class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<long long, int> mpp;

        for (auto &i : reservedSeats) {
            long long key = (1LL * i[0] << 32) | i[1];
            mpp[key] = 1;
        }

        unordered_set<int> rows;

        for (auto &i : reservedSeats)
            rows.insert(i[0]);

        long long ans = 2LL * (n - rows.size());

        for (int row : rows) {
            auto check = [&](int seat) {
                long long key = (1LL * row << 32) | seat;
                return mpp.find(key) != mpp.end();
            };

            bool t1 = !check(2) && !check(3) && !check(4) && !check(5);
            bool t2 = !check(4) && !check(5) && !check(6) && !check(7);
            bool t3 = !check(6) && !check(7) && !check(8) && !check(9);

            ans += (t1 && t3) ? 2 : (t1 || t2 || t3) ? 1 : 0;
        }

        return ans;
    }
};