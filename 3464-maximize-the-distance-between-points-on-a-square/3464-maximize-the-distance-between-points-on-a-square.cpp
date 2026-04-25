class Solution {
public:
    using ll = long long;

    bool check(vector<ll>& res, int side, int k, ll dist) {
        int n = res.size();
        ll peri = 1LL * side * 4;

        for (int i = 0; i < n; i++) {
            ll curr = res[i];
            int count = 1;
            int lastIdx = i;

            while (count < k) {
                auto it = lower_bound(res.begin(), res.end(), curr + dist);
                if (it == res.end()) break;

                lastIdx = it - res.begin();
                curr = *it;
                count++;
            }

            if (count == k && peri - (res[lastIdx] - res[i]) >= dist) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> res;

        for (auto &p : points) {
            int x = p[0], y = p[1];

            if (x == 0) res.push_back(y);
            else if (y == side) res.push_back((ll)side + x);
            else if (x == side) res.push_back((ll)3 * side - y);
            else res.push_back((ll)4 * side - x);
        }

        sort(res.begin(), res.end());

        ll left = 1, right = 4LL * side, ans = 0;

        while (left <= right) {
            ll mid = left + (right - left) / 2;

            if (check(res, side, k, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};