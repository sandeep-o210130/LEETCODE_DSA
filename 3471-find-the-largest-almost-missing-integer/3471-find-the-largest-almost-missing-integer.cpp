class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> arr(51,0);
        for(auto i:nums) arr[i]++;
        if(nums.size()==k) return *max_element(nums.begin(),nums.end());
        else if(k==1){
            int maxx=-1;
            for(auto i:nums) if(arr[i]==1) maxx=max(maxx,i);
            return maxx;
        }
        else if((arr[nums[0]]==1) && (arr[nums[nums.size()-1]]==1)) return max(nums[0],nums[nums.size()-1]);
        else if(arr[nums[0]]==1) return nums[0];
        else if(arr[nums[nums.size()-1]]==1) return nums[nums.size()-1];
        return -1;
    }
};