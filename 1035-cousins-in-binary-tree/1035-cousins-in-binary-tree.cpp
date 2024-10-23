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
    void parentChildMapping(TreeNode* &root, unordered_map<int, int> &mp, int parent){
        if(root == NULL) return;
        mp[root->val] = parent;
        parentChildMapping(root->left, mp, root->val);
        parentChildMapping(root->right, mp, root->val);
    }
    void elementLevelMapping(TreeNode* &root, unordered_map<int, int> &mp, int level){
        if(root == NULL) return;
        mp[root->val] = level;
        elementLevelMapping(root->left, mp, level + 1);
        elementLevelMapping(root->right, mp, level + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        parentChildMapping(root, mp1, -1);
        elementLevelMapping(root, mp2, 0);
        if(mp1[x] == mp1[y]) return false;
        else if(mp2[x] == mp2[y]) return true;
        else return false;
    }
};