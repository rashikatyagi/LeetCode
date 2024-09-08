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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* temp = head->next->next;
        head->next->next = head;
        ListNode* newhead = head->next;
        if(temp == NULL){
            head->next = swapPairs(NULL);
        }
        else{
            head->next = swapPairs(temp);
        }
        return newhead;
    }
};