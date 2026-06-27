class Solution {
public:
    int maximumLength(vector<int>&nums) {
        unordered_map<long,int> mpp;
        long long ones=0;
        for(auto i: nums) (i==1)?ones++:mpp[i]++;
        long long maxx=0;
        for(auto [i,j]:mpp){
            long c=1,i1=i;
            while(mpp[i1]>=2 && mpp.count(i1*i1)){
                c+=2;
                i1*=i1;
            }
            maxx=max((long long)maxx,(long long)c);
        }
        return max((long long)maxx,(long long) ones-!(ones&1));
    }
};