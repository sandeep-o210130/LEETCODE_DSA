class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        unordered_map<int, int> mp;
        int currSum = 0;

        mp[0] = 1;

        long long validLeftPoints = 0;
        long long result = 0;

        for (int x : nums) {

            if (x == target) {
                validLeftPoints += mp[currSum];
                currSum++;
            }
            else {
                currSum--;
                validLeftPoints -= mp[currSum];
            }

            mp[currSum]++;
            result += validLeftPoints;
        }

        return result;
    }
};