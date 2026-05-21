// Last updated: 21/05/2026, 18:34:12
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
    ListNode* rotateRight(ListNode* head, int k) {
        // Handle empty list or single-node list
        if (!head || !head->next || k == 0) return head;

        // 1. Calculate the length of the list and find the tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Adjust k to handle rotations larger than list length
        k = k % length;
        if (k == 0) return head;

        // 3. Make the list circular
        tail->next = head;
        // 4. Find the new tail: it is at (length - k) steps from the current head
        // or (length - k - 1) steps if starting from the head.
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        // 5. Set the new head and break the circular link
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
        
