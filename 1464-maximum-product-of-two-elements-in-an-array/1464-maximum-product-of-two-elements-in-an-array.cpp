class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx=INT_MIN,maxx2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=maxx){
                maxx2=maxx;
                maxx=nums[i];
            }
            else if(nums[i]>maxx2) maxx2=nums[i];
        }
        return (maxx-1)*(maxx2-1);
    }
};