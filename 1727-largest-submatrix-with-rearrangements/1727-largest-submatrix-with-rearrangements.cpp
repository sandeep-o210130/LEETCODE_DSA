class Solution {
public:
    int anss(vector<int> &a,int n){
        vector<int> l(n),r(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while((!s.empty()) && (a[s.top()]>=a[i])) s.pop();
            if(s.empty()) l[i]=0;
            else l[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while((!s.empty()) && (a[s.top()]>=a[i])) s.pop();
            if(s.empty()) r[i]=n-1;
            else r[i]=s.top()-1;
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,(r[i]-l[i]+1)*a[i]);
        }
        return ans;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            mat[0][i]=matrix[0][i]-0;
            for(int j=1;j<m;j++){
                int k = matrix[j][i]-0;
                if(k==0) mat[j][i]=0;
                else mat[j][i]=mat[j-1][i]+k;
            }
        }   
        int maxx = INT_MIN;
        for(int i=0;i<m;i++){
            sort(mat[i].begin(),mat[i].end());
            maxx = max(maxx,anss(mat[i],n));
        }
        return maxx;
    }
};