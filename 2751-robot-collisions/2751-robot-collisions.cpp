class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n) ;
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });

        stack<int> st;
        vector<bool> dead(n, false);

        for (int i : order) {
            if (directions[i] == 'R') {
                st.push(i) ;
            } else {
                while (!st.empty() && directions[st.top()] == 'R') {
                    int top = st.top();
                    if (healths[top] > healths[i]) {
                        healths[top]-- ;
                        dead[i] = true;
                        break;
                    } else if (healths[top] < healths[i]) {
                        healths[i]--;
                        dead[top] = true ;
                        st.pop();
                    } else {
                        dead[i] = true;
                        dead[top] = true ;
                        st.pop();
                        break;
                    }
                }
                if (!dead[i]) st.push(i);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (!dead[i]) result.push_back(healths[i]) ;

        return result;
    }
};