class Solution {
public:

    vector<int> parent, rankv;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;

        if(rankv[a] < rankv[b]) swap(a,b);
        parent[b] = a;
        if(rankv[a] == rankv[b]) rankv[a]++;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rankv.resize(n,0);

        for(int i=0;i<n;i++) parent[i] = i;

        for(auto &e : allowedSwaps){
            unite(e[0], e[1]);
        }

        unordered_map<int, vector<int>> groups;
        for(int i=0;i<n;i++){
            groups[find(i)].push_back(i);
        }

        int ans = 0;

        for(auto &[p, idxs] : groups){
            unordered_map<int,int> freq;

            for(int i : idxs) freq[source[i]]++;

            for(int i : idxs){
                if(freq[target[i]] > 0)
                    freq[target[i]]--;
                else
                    ans++;
            }
        }

        return ans;
    }
};