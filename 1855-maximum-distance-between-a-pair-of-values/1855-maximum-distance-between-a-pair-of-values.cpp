class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        int i=0,j=0,maxx=INT_MIN;
        while(i<m && j<n){
            while((j<n) && (nums1[i]<=nums2[j])) j++;
            maxx = max(maxx,j-1-i);
            i++;
        }
        return (maxx==-1)?0:maxx;
    }
};