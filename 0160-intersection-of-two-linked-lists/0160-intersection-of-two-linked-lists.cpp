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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB)return NULL;

        ListNode* clone1 = headA;
        ListNode* clone2 = headB;

        while(headA != headB){
            if(headA == NULL){
                headA = clone2;
            }
            else{
                headA = headA->next;
            }
            if(headB == NULL){
                headB = clone1;
            }
            else{
                headB = headB->next;
            }
        }
        return headA;
    }
};