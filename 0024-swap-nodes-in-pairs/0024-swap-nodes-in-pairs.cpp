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
    ListNode* solve(ListNode* temp1, ListNode* temp2){
        //base case 
        if(temp1 == NULL) return NULL;
        if(temp2 == NULL) return temp1;
        ListNode* temp = temp2->next;
        temp2->next = temp1;
        if(temp == NULL)
            temp1->next = solve(NULL, NULL);
        else
            temp1->next = solve(temp, temp->next);
        return temp2;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        return solve(head, head->next);
    }
};