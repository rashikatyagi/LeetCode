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
class Solution {
public:
    void reverseLL(ListNode* &head){
        if(head == NULL || head->next == NULL){
            return;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextnode = head->next;
        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = nextnode;
            if(nextnode != NULL) nextnode = nextnode->next;
        }
        head = prev;
    }
    int pairSum(ListNode* head) {
        if(head == NULL || head->next == NULL) return 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL) fast = fast->next;
        }
        ListNode* new_head = slow;
        reverseLL(new_head);
        int maxsum = INT_MIN;
        while(new_head != NULL){
            maxsum = max(maxsum, head->val + new_head->val);
            head = head->next;
            new_head = new_head->next;
        }
        return maxsum;
    }
};