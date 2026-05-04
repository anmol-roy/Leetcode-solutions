// Last updated: 04/05/2026, 15:43:09
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // Save this to connect at the end
        
        // Use even and even->next to stay within bounds
        while(even != NULL && even->next != NULL) {
            odd->next = odd->next->next;   // Connect odd to next odd node
            odd = odd->next;               // Move odd forward
            
            even->next = even->next->next; // Connect even to next even node
            even = even->next;             // Move even forward
        }
        
        odd->next = evenHead; // Connect the end of odd list to start of even list
        return head;
    }
};
