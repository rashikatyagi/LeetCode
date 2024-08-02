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
    void inorder_fun(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        inorder_fun(root->left, ans);
        ans.push_back(root->val);
        inorder_fun(root->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorder_fun(root, inorder);
        for(int i = 1 ; i < inorder.size() ; i++){
            if(inorder[i] <= inorder[i - 1]) return false;
        }
        return true;
    }
};