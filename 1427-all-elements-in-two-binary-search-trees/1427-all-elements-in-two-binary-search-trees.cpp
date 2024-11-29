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
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> bst1;
        vector<int> bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);
        int n = bst1.size();
        int m = bst2.size();
        vector<int> ans;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(bst1[i] < bst2[j]) {
                ans.push_back(bst1[i++]);
            }
            else {
                ans.push_back(bst2[j++]);
            }
        }
        while(i < n){
            ans.push_back(bst1[i++]);
        }
        while(j < m){
            ans.push_back(bst2[j++]);
        }
        return ans;
    }
};