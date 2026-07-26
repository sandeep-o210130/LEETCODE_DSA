class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a,b,c,d,e,ele1=INT_MIN,ele2=INT_MIN,ele3=INT_MIN,ele4=INT_MAX,ele5=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>ele1){
                c=b;
                ele3=ele2;
                b=a;
                ele2=ele1;
                a=i;
                ele1=nums[i];
            }
            if(nums[i]>ele2 && i!=a){
                c=b;
                ele3=ele2;
                b=i;
                ele2=nums[i];
            }
            if(nums[i]>ele3 && i!=a && i!=b){
                c=i;
                ele3=nums[i];
            }
            if(nums[i]<ele4){
                e=d;
                ele5=ele4;
                d=i;
                ele4=nums[i];
            }
            if(nums[i]<ele5 && d!=i){
                e=i;
                ele5=nums[i];
            }
        }
        return max(ele1*ele2*ele3,max(max(ele1,ele2),ele3)*ele4*ele5);
    }
};