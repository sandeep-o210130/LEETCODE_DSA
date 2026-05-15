class Solution {
public:
    int findMin(vector<int>& nums) {
        int minn = nums[0];
        int beg=0,end=nums.size()-1;
        while(beg<=end){
            int mid = beg+((end-beg)/2);
            if(nums[mid]>=nums[0]) beg=mid+1;
            else{
                minn = min(minn,nums[mid]);
                end = mid-1;
            }
        }
        return minn;
    }
};