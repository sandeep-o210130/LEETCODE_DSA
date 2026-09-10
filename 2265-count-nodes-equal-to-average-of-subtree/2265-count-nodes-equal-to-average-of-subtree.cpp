/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int , int> sumSubtree(TreeNode* node){
        if(!node) return {0 , 0};
        int cnt = 1;
        int totalSum = node->val;

        if(node->left){
            auto[leftSum , leftCnt] = sumSubtree(node->left);
            totalSum += leftSum;
            cnt += leftCnt;
        }

        if(node->right){
           auto[rightSum , rightCnt] = sumSubtree(node->right);

           totalSum += rightSum;
           cnt += rightCnt;
        }
        return {totalSum , cnt};// returns totalsum in subtree and total no of nodes in subtree;

    }

    int solve(TreeNode* node ){
        if(!node) return 0;
        int ans = 0;

        auto[sum , cnt] = sumSubtree(node);
        if(sum/cnt == node->val) ans++;

        ans += solve(node->left);
        ans += solve(node->right);

        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        // for avg we need no of node and sum of nodes in subtree right 
        // so we write fn to get sum and no of nodes in subtree 
        if(!root) return 0;

        return solve(root);
       

    }
};