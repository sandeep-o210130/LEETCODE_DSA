class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int q : queries) {
            int val = nums[q];
            auto &vec = mpp[val];

            if(vec.size() <= 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            int res = INT_MAX;

            if((idx + 1) < vec.size()) {
                int d = abs(vec[idx+1] - q);
                res = min(res, min(d, n - d));
            } else {
                int d = abs(q - vec[0]);
                res = min(res, min(d, n - d));
            }

            if(idx > 0) {
                int d = abs(q - vec[idx-1]);
                res = min(res, min(d, n - d));
            } else {
                int d = abs(q - vec.back());
                res = min(res, min(d, n - d));
            }

            ans.push_back(res);
        }

        return ans;
    }
};