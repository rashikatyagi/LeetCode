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
    bool check(TreeNode* root, TreeNode* subroot){
        if(root == NULL && subroot == NULL) return true;
        else if(!root || !subroot) return false;
        if(root->val != subroot->val) return false;
        bool left = check(root->left, subroot->left);
        bool right = check(root->right, subroot->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root == NULL) return false;
        if(root->val == subroot->val){
            bool ans = check(root, subroot);
            if(ans) return ans; 
        }
        bool ans1 = isSubtree(root->left, subroot);
        bool ans2 = isSubtree(root->right, subroot);
        return ans1 || ans2;
    }
};