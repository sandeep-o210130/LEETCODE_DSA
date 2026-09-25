class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        return dfs(expression, 0, expression.size() - 1);
    }

private:
    vector<string> dfs(string &s, int start, int end) {
        set<string> result;

        vector<vector<string>> groups(1);
        int depth = 0;
        int left = 0;

        for (int i = start; i <= end; i++) {
            if (s[i] == '{' && ++depth == 1) {
                left = i + 1;
            }
            else if (s[i] == '}' && --depth == 0) {
                merge(groups, dfs(s, left, i - 1));
            }
            else if (s[i] == ',' && depth == 0) {
                groups.push_back({});
            }
            else if (depth == 0) {
                merge(groups, {string(1, s[i])});
            }
        }

        for (auto &group : groups) {
            for (auto &word : group) {
                result.insert(word);
            }
        }

        return vector<string>(result.begin(), result.end());
    }

    void merge(vector<vector<string>> &groups,
               vector<string> words) {

        vector<string> &current = groups.back();

        if (current.empty()) {
            current = words;
            return;
        }

        vector<string> combined;

        for (string &a : current) {
            for (string &b : words) {
                combined.push_back(a + b);
            }
        }

        current = combined;
    }
};