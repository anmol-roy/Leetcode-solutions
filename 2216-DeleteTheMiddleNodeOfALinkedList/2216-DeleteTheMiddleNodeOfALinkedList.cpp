// Last updated: 06/07/2026, 09:53:02
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Corrected base case: do NOT manually delete head here
        if (head == NULL || head->next == NULL) {
            return NULL; 
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev =  slow;
            slow =    slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow; // This delete is correct because this node is now unlinked

        return head;
    }
};
