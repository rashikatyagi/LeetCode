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
    //This only works when condition is given that both p and q always exist in bst
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        //if(root == NULL) return NULL;

        //CASE 1 both p and q are smaller than current node-> answer will be in left node
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        //CASE 2 both p and q are larger than current node-> answer will be in right node
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }

        // p - smaller and q - larger or p - larger and q - smaller than current node element
        return root;
    }
};