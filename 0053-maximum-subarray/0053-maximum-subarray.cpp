class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),i=0,sum=0,maxx=INT_MIN;
        while(i<n){
            sum+=nums[i];
            maxx = max(maxx,sum);
            if(sum<0)sum=0;
            i++;
        }
        return maxx;
    }
};