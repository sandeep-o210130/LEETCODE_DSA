class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum=0,sum2=0,idx=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]) sum+=nums[i];
            else{
                if(idx==-1) idx=i;
                sum2+=nums[i+1];
            }
        }
        if(sum>sum2) return 0;
        else if(sum<sum2) return 1;
        else return -1;
    }
};