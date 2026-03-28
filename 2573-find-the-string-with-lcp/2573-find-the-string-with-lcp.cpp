class Solution {
public:
    static string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string s(n, 'a'-1);
        int id=-1;
        for(int i=0; i<n; i++){
            if (s[i]>='a') continue; //already assigned
            if (++id>=26) return ""; //char count > 26
            for(int j=0; j<n; j++)
                if(lcp[i][j]) s[j]='a'+id; //assign a new char to a new group
        }
        for(int i=0; i<n; i++){
            // check diagonal
            if (lcp[i][i]!=n-i) return "";

            for(int j=0; j<i; j++){
                const int x=lcp[i][j];
                // must be symmetric
                if (x!=lcp[j][i]) return "";
                //Conflict check
                int y = 0;
                if (s[i] == s[j]) {
                    if (i + 1 < n && j + 1 < n)
                        y = 1 + lcp[i + 1][j + 1];
                    else
                        y = 1;
                } else {
                    y = 0;
                }

                if (x!=y) return "";
            }
        }
        return s;
    }
};