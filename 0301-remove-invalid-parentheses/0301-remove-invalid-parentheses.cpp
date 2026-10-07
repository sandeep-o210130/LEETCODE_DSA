class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<vector<unordered_set<string>>> memo(n + 1,
            vector<unordered_set<string>>(n + 1));

        unordered_set<string> valid = dfs(s, 0, 0, memo);

        int maxLen = 0;
        for (const string& str : valid) {
            maxLen = max(maxLen, (int)str.size());
        }

        vector<string> ans;
        for (const string& str : valid) {
            if (str.size() == maxLen) {
                ans.push_back(str);
            }
        }

        return ans;
    }

private:
    unordered_set<string> dfs(string& s, int i, int open,
                               vector<vector<unordered_set<string>>>& memo) {
        unordered_set<string> ans;

        if (open < 0) return ans;

        if (!memo[i][open].empty()) {
            return memo[i][open];
        }

        if (i == s.size()) {
            if (open == 0) {
                ans.insert("");
            }
            return memo[i][open] = ans;
        }

        char c = s[i];

        if (c == '(' || c == ')') {
            auto skipped = dfs(s, i + 1, open, memo);
            ans.insert(skipped.begin(), skipped.end());
        }

        int nextOpen = open;

        if (c == '(') nextOpen++;
        else if (c == ')') nextOpen--;

        auto kept = dfs(s, i + 1, nextOpen, memo);

        for (const string& suffix : kept) {
            ans.insert(string(1, c) + suffix);
        }

        return memo[i][open] = ans;
    }
};