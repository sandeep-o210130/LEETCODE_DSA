/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
const int N = 100001;
bitset<N> seen = 0;
int parent[N] = {0};//parent val
TreeNode* node[N];// array for TreeNode*
TreeNode POOL[N];// array for TreeNode
int ptr=0;
class Solution {
public:
    static TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int root=-1;
        ptr=0;
        int M=0;

        for (auto& d : descriptions) {
            int x = d[0], y = d[1], l = d[2];
            M=max(M, max(x, y));
            if (!seen[x]) {
                node[x] = new (&POOL[ptr++]) TreeNode(x);
                seen[x]=1;
                if (parent[x] == 0)
                    root = x;
            }
            if (!seen[y]) {
                node[y] = new (&POOL[ptr++]) TreeNode(y);
                seen[y] = 1;
            }
            parent[y] = x;
            if (l)
                node[x]->left=node[y];
            else
                node[x]->right=node[y];
        }
        while (parent[root] != 0)// find real root
            root = parent[root];
        auto* ans=node[root];

        for (auto& d : descriptions) {
            int x = d[0], y = d[1];
            seen[x]= seen[y] = 0;
            parent[x] = parent[y] = 0;
        }
        
        return ans;
    }
};