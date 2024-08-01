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
    int height(TreeNode* root, int &D) {
        if(root == NULL) return 0;
        int left = 1 + height(root->left, D);
        int right = 1 + height(root->right, D);
        int currD = left + right - 2;
        D = max(D, currD);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int D = 0;
        height(root, D);
        return D;
    }
};