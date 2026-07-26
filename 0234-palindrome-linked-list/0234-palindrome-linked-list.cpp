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
    ListNode* reverseALinkedList(ListNode* head) {
        ListNode* dummy = nullptr;
            while (head != nullptr) {
                ListNode* head2 = head->next;
                head->next = dummy;  // Link Breaker
                dummy = head;
                head = head2;
            }
        return dummy;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        //Slow and Fast pointers
        while(fast->next != NULL and fast->next->next != NULL){ 
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverseALinkedList(slow->next);
        slow = slow->next; // slow is the starting of the new reversed linkedlist. 

        while(slow != NULL){
            if(slow->val != head->val){
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};