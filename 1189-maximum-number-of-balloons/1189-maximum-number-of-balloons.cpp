class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> a(26,0);
        for(auto i:text) a[i-'a']++;
        int minn=INT_MAX;
        string s = "balloon";
        for(auto i:s){
            if(i=='l' || i=='o') minn = min(minn,a[i-'a']/2);
            else minn = min(minn,a[i-'a']);
        };
        return minn;
    }
};