/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode* ans_left = lowestCommonAncestor(root->left, p, q);
        TreeNode* ans_right = lowestCommonAncestor(root->right, p, q);
        if(ans_left && ans_right) return root;
        if(!ans_left && !ans_right) return NULL;
        if(ans_left) return ans_left;
        else return ans_right;
    }
};