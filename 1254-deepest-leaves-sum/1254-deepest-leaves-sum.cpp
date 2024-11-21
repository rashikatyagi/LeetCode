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
    int height(TreeNode* &root){
        while(root == NULL) return 0;
        return max(1 + height(root->left), 1 + height(root->right));
    }
    void getSum(TreeNode* &root, int level, int &height, int &sum){
        if(root == NULL) return; 
        if(root->left == NULL && root->right == NULL){
            //leaf node
            if(level == height) sum += root->val;
            return;
        }
        getSum(root->left, level + 1, height, sum);
        getSum(root->right, level + 1, height, sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth = height(root);
        int answer = 0;
        getSum(root, 1, depth, answer);
        return answer;
    }
};