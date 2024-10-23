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
    void modifyTree(TreeNode* &root, vector<int> &levelSum, int parentSum, int level){
        if(root == NULL) return;
        if(parentSum == levelSum[level]){
            root->val = 0;
        }
        else{
            root->val = levelSum[level] - parentSum;
        }
        int currsum = 0;
        if(root->left) currsum += root->left->val;
        if(root->right) currsum += root->right->val;
        modifyTree(root->left, levelSum, currsum, level + 1);
        modifyTree(root->right, levelSum, currsum, level + 1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
       vector<int> levelSum;
       queue<TreeNode*> q;
       q.push(root);
       q.push(NULL);
       int sum = 0;
       while(!q.empty()){
        TreeNode* frontNode = q.front();
        q.pop();
        if(frontNode == NULL){
            levelSum.push_back(sum);
            sum = 0;
            if(!q.empty()) q.push(NULL);
        }
        else{
            sum += frontNode->val;
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
        }
       }
        modifyTree(root, levelSum, root->val, 0);
        return root;
    }
};