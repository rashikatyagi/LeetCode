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
    void countNode(TreeNode* &root, int &count){
        if(root == NULL) return;
        count++;
        countNode(root->left, count);
        countNode(root->right, count);
    }
    bool IsCBT(TreeNode* &root, int i, int n){
        if(root==NULL) return true;
        if(i>=n) return false;
        bool left=IsCBT(root->left,2*i+1,n);
        bool right=IsCBT(root->right,2*i+2,n);
        return (left && right);
    }
    bool isCompleteTree(TreeNode* root) {
        int n = 0;
        countNode(root, n);
        return IsCBT(root, 0, n);
    }
};