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
    void getSum(TreeNode* root, int level, int &maxLevel, int &sum){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            if(level > maxLevel){
                maxLevel = level;
                sum = root->val;
            }
            else if(level == maxLevel){
                sum += root->val;
            }
            return;
        } 
        getSum(root->left, level + 1, maxLevel, sum);
        getSum(root->right, level + 1, maxLevel, sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int answer = 0 ;
        int maxlevel = 1;
        getSum(root, 1, maxlevel, answer);
        return answer;
    }
};