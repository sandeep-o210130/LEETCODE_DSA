class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int c=0,maxx=0;
        for(auto i:costs) maxx=max(maxx,i);
        vector<int> ans(maxx+1,0);
        for(auto i:costs) ans[i]++;
        int rem=coins;
        for(int i=1;i<=maxx;i++){
            if(ans[i]>0){
                int bst = min(ans[i],rem/i);
                c=c+bst;
                rem-=(bst*i);
                if(bst==0) break;
            }
        }
        return c;
    }
};