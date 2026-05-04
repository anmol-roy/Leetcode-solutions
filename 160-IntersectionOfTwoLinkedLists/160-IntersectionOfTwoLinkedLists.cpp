// Last updated: 04/05/2026, 15:43:48
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
    // Helper function to get the length of the list
    int getLeng(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLeng(headA);
        int lenB = getLeng(headB);

        while (lenA > lenB) {
            lenA--;
            headA = headA->next;
        }
        while (lenB > lenA) {
            lenB--;
            headB = headB->next; 
        }

        while (headA != headB) {
            headA = headA->next; 
            headB = headB->next; 
        }
        
        return headA;
    }
};
