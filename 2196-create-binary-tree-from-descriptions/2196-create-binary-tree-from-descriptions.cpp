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

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mpp1;
        unordered_map<int,int> mpp2;
        for(auto i:descriptions){
            TreeNode *p,*c;
            if(mpp1.find(i[0])!=mpp1.end()) p = mpp1[i[0]];
            else{
                p = new TreeNode(i[0]);
                mpp1[i[0]]=p;
            }
            if(mpp1.find(i[1])!=mpp1.end()) c = mpp1[i[1]];
            else{
                c = new TreeNode(i[1]);
                mpp1[i[1]]=c;
            }
            if(i[2]) p->left=c;
            else p->right=c;
            mpp2[i[1]]=1;
        }
        for(auto i:descriptions){
            if(mpp2.find(i[0])==mpp2.end()) return mpp1[i[0]];
        }
        return nullptr;
    }
};