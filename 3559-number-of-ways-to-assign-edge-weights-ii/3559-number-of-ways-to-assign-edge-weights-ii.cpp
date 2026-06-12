class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<vector<int>> up;
    vector<long long> pow2;
    int LOG;

    void dfs(int node, int par) {
        up[node][0] = par;

        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1)
                up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (auto nxt : adj[node]) {
            if (nxt == par) continue;
            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--) {
            if ((diff >> i) & 1)
                u = up[u][i];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        LOG = 20;
        adj.resize(n + 1);
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, -1);

        pow2.resize(n + 1);
        pow2[0] = 1;

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int L = lca(u, v);

            int k = depth[u] + depth[v] - 2 * depth[L];

            if (k == 0)
                ans.push_back(0);
            else
                ans.push_back(pow2[k - 1]);
        }

        return ans;
    }
};