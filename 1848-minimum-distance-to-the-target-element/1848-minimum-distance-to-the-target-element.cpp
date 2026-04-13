class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) minn = min(minn,abs(start-i));
        }
        return minn;
    }
};