class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0),right(n,0),ans(n,0);
        for(int i=n-2;i>=0;i--) right[i]=nums[i+1]+right[i+1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i-1];
            ans[i-1]=abs(left[i-1]-right[i-1]);
        }
        ans[n-1]=abs(left[n-1]-right[n-1]);
        return ans;
    }
};