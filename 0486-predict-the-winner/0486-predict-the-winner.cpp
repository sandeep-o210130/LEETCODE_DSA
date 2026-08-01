class Solution {
public:
    bool playgame(int turn, int s1, int s2, int i, int j, vector<int>& nums) {
        if (i > j) {
            return s1 >= s2;
        }

        if (turn) {
            return playgame(0, s1 + nums[i], s2, i + 1, j, nums) 
                || playgame(0, s1 + nums[j], s2, i, j - 1, nums);
        }
        return playgame(1, s1, s2 + nums[i], i + 1, j, nums) 
            && playgame(1, s1, s2 + nums[j], i, j - 1, nums);

    }
    bool predictTheWinner(vector<int>& nums) {
        return playgame(1, 0, 0, 0, nums.size() - 1, nums);
    }
};