class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        // (value, original index)
        vector<pair<int,int>> v;

        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});

        // Sort by value
        sort(v.begin(), v.end());

        int cmp = 1;

        // group -> {indices, values}
        unordered_map<int, pair<set<int>, multiset<int>>> mpp;

        mpp[1].first.insert(v[0].second);
        mpp[1].second.insert(v[0].first);

        // Make groups
        for (int i = 1; i < v.size(); i++) {

            // Gap too big -> new squad 💀
            if (v[i].first - v[i - 1].first > limit)
                cmp++;

            mpp[cmp].first.insert(v[i].second);
            mpp[cmp].second.insert(v[i].first);
        }

        // Smallest value goes to smallest index
        for (auto& it : mpp) {

            auto& [indices, values] = it.second;

            auto i = indices.begin();
            auto val = values.begin();

            while (i != indices.end()) {
                nums[*i] = *val;
                i++;
                val++;
            }
        }

        return nums;
    }
};