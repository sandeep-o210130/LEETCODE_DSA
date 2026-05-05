class NumArray {
public:
    vector<int> temp;
    NumArray(vector<int>& nums) {
        temp.resize(nums.size());
        temp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            temp[i]=temp[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return temp[right];
        return temp[right]-temp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */