/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL)return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* finder = head; // only move after slow and fast meets.

        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                // return true. 
                // from here to intersection is same as head to intersection. 
                while(slow != finder){
                    slow = slow->next;
                    finder = finder->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};