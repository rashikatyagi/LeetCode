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
    bool solve(TreeNode* root, long long int lowerBound, long long int upperBound){
        if(root == NULL) return true;
        return ((root->val > lowerBound) 
        && (root->val < upperBound) 
        && solve(root->left, lowerBound, root->val) 
        && solve(root->right, root->val, upperBound));
    }
    bool isValidBST(TreeNode* root) {
        long long int lowerBound = -2147483658;
        long long int upperBound = 2147483657;
        return solve(root, lowerBound, upperBound);
    }
};