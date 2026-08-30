class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxx=INT_MIN,minn = INT_MAX,a=-1,b=-1,t=nums.size();
        for(int i=0;i<nums.size();i++){
            if(maxx<nums[i]){
                maxx=nums[i];
                a=i;
            }
            if(minn>nums[i]){
                minn=nums[i];
                b=i;
            }
        }
        cout<<a<<b<<endl;
        int m = max(a,b),n=min(a,b);
        return min(
                n+1 + min(m - n, t - m),
                t - m + min(n+1, m - n)
        );   
    }
};