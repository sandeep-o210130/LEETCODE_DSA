class Solution {
public:
    string processStr(string s) {
        deque<char> dq;
        bool rev = false;

        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                if (!rev)
                    dq.push_back(c);
                else
                    dq.push_front(c);
            }
            else if (c == '*') {
                if (!dq.empty()) {
                    if (!rev)
                        dq.pop_back();
                    else
                        dq.pop_front();
                }
            }
            else if (c == '%') {
                rev = !rev;
            }
            else if (c == '#') {
                deque<char> cur = dq;

                if (!rev) {
                    for (char ch : cur)
                        dq.push_back(ch);
                } else {
                    for (auto it = cur.rbegin(); it != cur.rend(); ++it)
                        dq.push_front(*it);
                }
            }
        }

        string ans;
        ans.reserve(dq.size());

        if (!rev) {
            for (char ch : dq)
                ans.push_back(ch);
        } else {
            for (auto it = dq.rbegin(); it != dq.rend(); ++it)
                ans.push_back(*it);
        }

        return ans;
    }
};