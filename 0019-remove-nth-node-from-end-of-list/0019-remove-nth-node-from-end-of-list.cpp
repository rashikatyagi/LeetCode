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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        //move the fast pointer n steps so that it is n steps ahead
        for(int i = 0 ; i < n ; i++){
            fast = fast->next;
        }
        //case if n == length of the linked list
        if(fast == NULL){
            return head->next;
        }
        //move the slow and fast pointers together to reach the node just before the node to delete
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        //now slow is pointing to the node before the node to be deleted
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;
        return head;
    }
};