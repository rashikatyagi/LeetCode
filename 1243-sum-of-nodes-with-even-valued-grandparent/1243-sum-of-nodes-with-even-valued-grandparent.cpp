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
    void getSum(TreeNode* &root, int parent, int grandparent, int &sum){
        if(root == NULL) return;
        if(!(grandparent & 1)){
            sum += root->val;
        }
        getSum(root->left, root->val, parent, sum);
        getSum(root->right, root->val, parent, sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int answer = 0;
        getSum(root, -1, -1, answer);
        return answer;
    }
};