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
    void formingGST(TreeNode* root, int &greatersum){
        if(root == NULL) return;
        formingGST(root->right, greatersum);
        greatersum += root->val;
        root->val = greatersum;
        formingGST(root->left, greatersum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        formingGST(root, sum);
        return root;
    }
};