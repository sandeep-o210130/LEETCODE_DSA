class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int c=1,ind=1;
        for(int i=1;i<nums.size();i++){
            c++;
            if(nums[i]!=nums[i-1]) c=1;
            if(c<=k){
                nums[ind]=nums[i];
                ind++;
            }
        }
        c = nums.size()-ind;
        while(c>0){
            nums.pop_back();
            c--;
        }
        return nums;
    }
};