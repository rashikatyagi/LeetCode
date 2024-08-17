/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class compare {
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int k = lists.size();
        for(int i = 0 ; i < k ; i++){
            ListNode* listHead = lists[i];
            if(listHead) pq.push(listHead);
        }
        ListNode* head = NULL;
        ListNode* temp = NULL;
        while(!pq.empty()){
            ListNode* front = pq.top();
            pq.pop();
            ListNode* newnode = new ListNode(front->val);
            if(head == NULL){
                head = newnode;
                temp = head;
            }
            else{
                temp->next = newnode;
                temp = temp->next;
            }
            if(front->next){
                pq.push(front->next);
            }
        }
        return head;
    }
};