class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>cnt(n+1);

        for(auto item:items) {
            int f = item[0];
            cnt[f]++;
        }

        for(int i=1;i<=n;i++) {
            for(int j=2*i;j<=n;j+=i) {
                cnt[i] += cnt[j];
            }
        }

        int copies = 0;
        long long cost = 0;

        sort(items.begin(), items.end(), [&](const auto &u, const auto &v) {
            return u[1] < v[1];
        });

        int mn = items[0][1];

        for(auto item:items) {
            int f = item[0], p = item[1];
            if(p >= 2*mn and cnt[f] > 1) continue;
            int free_cp = cnt[f]-1;
            if((long long)budget >= cost+(long long)free_cp*p) {
                cost += free_cp*p;
                copies += 2*free_cp;
            } else {
                free_cp = (budget - cost)/p;
                cost += free_cp*p;
                copies += 2*free_cp;
            }
        }

        return copies + (budget-cost)/mn;
    }
};