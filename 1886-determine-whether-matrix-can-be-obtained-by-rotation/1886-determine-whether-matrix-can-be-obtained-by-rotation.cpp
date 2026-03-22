class Solution {
public:
    bool check(vector<vector<int>>& a,vector<vector<int>>& b){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]!=b[i][j]) return false;
            }
        }
        return true;
    }
    void row_reverse(vector<vector<int>>& a){
        for(int i=0;i<a.size();i++) reverse(a[i].begin(),a[i].end());
    }
    void trans(vector<vector<int>> &a){
        vector<vector<int>> temp(a.size(),vector<int> (a[0].size(),0));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                temp[i][j]=a[j][i];
            }
        }
        a=temp;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            if(check(mat,target)) return true;
            trans(mat);
            row_reverse(mat);
        }
        return false;
    }
};