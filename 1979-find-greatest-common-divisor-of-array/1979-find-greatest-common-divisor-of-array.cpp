class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = *max_element(nums.begin(),nums.end()), b = *min_element(nums.begin(),nums.end());
        return __gcd(a,b);
    }
};