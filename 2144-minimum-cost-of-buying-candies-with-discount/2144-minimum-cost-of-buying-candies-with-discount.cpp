class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int rem=0;
        for(int i=cost.size()-3;i>=0;i=i-3) rem=rem+cost[i];
        return accumulate(cost.begin(),cost.end(),0)-rem;
    }
};