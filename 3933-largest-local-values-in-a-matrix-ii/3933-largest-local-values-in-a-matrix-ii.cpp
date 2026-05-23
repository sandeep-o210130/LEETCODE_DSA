class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int,int>> pos[201];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pos[matrix[i][j]].push_back({i,j});
            }
        }

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int x = matrix[i][j];

                if(x==0) continue;

                bool ok=true;

                int r1=max(0,i-x);
                int r2=min(m-1,i+x);

                int c1=max(0,j-x);
                int c2=min(n-1,j+x);

                for(int val=x+1; val<=200 && ok; val++){

                    for(auto &p : pos[val]){

                        int r=p.first;
                        int c=p.second;

                        if(r<r1 || r>r2 || c<c1 || c>c2)
                            continue;

                        if((r==i-x || r==i+x) &&
                           (c==j-x || c==j+x))
                            continue;

                        ok=false;
                        break;
                    }
                    if(ok==false) break;
                }

                if(ok) ans++;
            }
        }

        return ans;
    }
};