class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int c=0;
        for(auto i:costs){
            if(coins>=i){
                coins-=i;
                c++;
            }
            else break;
        }
        return c;
    }
};