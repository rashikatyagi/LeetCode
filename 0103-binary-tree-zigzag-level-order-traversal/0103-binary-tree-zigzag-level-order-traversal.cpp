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
    void solve(TreeNode* root, vector<vector<int> > &ans){
        if(root == NULL) return ;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> curr;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                if(ans.size() & 1) reverse(curr.begin(), curr.end());
                ans.push_back(curr);
                curr.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                curr.push_back(temp->val);
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, ans);
        return ans;
    }
};