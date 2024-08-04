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
    TreeNode* solve(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        TreeNode* newnode = new TreeNode(root->val);
        newnode->left = solve(root->right);
        newnode->right = solve(root->left);

        return newnode;
    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};