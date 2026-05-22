class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n=nums.size()-1;
        int beg=0,end=n;

        while(beg<=end){

            int mid=beg+(end-beg)/2;

            if(nums[mid]==target) return mid;

            if(nums[mid]<nums[n] && target<nums[n]){

                if(target<nums[mid])
                    end=mid-1;
                else
                    beg=mid+1;
            }

            else if(nums[mid]>nums[n] && target>nums[n]){

                if(target<nums[mid])
                    end=mid-1;
                else
                    beg=mid+1;
            }

            else if(nums[mid]<nums[n] && target>nums[n])
                end=mid-1;

            else
                beg=mid+1;
        }

        return -1;
    }
};