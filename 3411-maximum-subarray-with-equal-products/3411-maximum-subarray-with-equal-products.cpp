class Solution {
public:
    int maxLength(vector<int>& nums) {
        int sol=1;
        for(int i=0;i<nums.size();i++){
            int product=nums[i],gcdVal=nums[i],lcmVal=nums[i];
            for(int j=i+1;j<nums.size();j++){
                gcdVal=gcd(gcdVal,nums[j]);
                lcmVal=lcm(lcmVal,nums[j]);
                product*=nums[j];
                if(gcdVal*lcmVal==product)
                sol=max(sol,j-i+1);
                else
                break;
            }
        }
        return sol;
    }
};