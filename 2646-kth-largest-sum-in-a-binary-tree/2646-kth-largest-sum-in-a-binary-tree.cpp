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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        q.push(root);
        q.push(NULL);
        long long currSum = 0;
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            if(frontNode == NULL){
                //level completed
                if(pq.size() < k){
                    pq.push(currSum);
                }
                else if(pq.size() == k && currSum > pq.top()){
                    pq.pop();
                    pq.push(currSum);
                }
                currSum = 0;
                if(!q.empty()) q.push(NULL);
            }
            else{
                currSum += frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
        }
        if(pq.size() < k) return -1;
        return pq.top();
    }
};