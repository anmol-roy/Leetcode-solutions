// Last updated: 06/07/2026, 09:53:00
class Solution {
public:
    int pairSum(ListNode* head) {
        // 1. Find the middle of the linked list using slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow now points to the beginning of the second half
        
        // 2. Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // prev now points to the head of the reversed second half
        
        // 3. Track the maximum twin sum by iterating through both halves
        int maxVal = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        
        while (secondHalf != nullptr) {
            int currentTwinSum = firstHalf->val + secondHalf->val;
            maxVal = max(maxVal, currentTwinSum);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return maxVal;
    }
};
