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
    int ans = 0;
    // this function checks how many paths from this root
    void solve(TreeNode* root, long long int sum){
        if(!root) return;
        if(sum == root->val) ans++;
        solve(root->left, sum - root->val);
        solve(root->right, sum - root->val); 
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            solve(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};