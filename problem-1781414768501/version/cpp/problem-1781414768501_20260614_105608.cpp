// Last updated: 14/06/2026, 10:56:08
1class Solution {
2public:
3    int pairSum(ListNode* head) {
4        // 1. Find the middle of the linked list using slow & fast pointers
5        ListNode* slow = head;
6        ListNode* fast = head;
7        while (fast != nullptr && fast->next != nullptr) {
8            slow = slow->next;
9            fast = fast->next->next;
10        }
11        
12        // slow now points to the beginning of the second half
13        
14        // 2. Reverse the second half of the linked list
15        ListNode* prev = nullptr;
16        ListNode* curr = slow;
17        while (curr != nullptr) {
18            ListNode* nextNode = curr->next;
19            curr->next = prev;
20            prev = curr;
21            curr = nextNode;
22        }
23        
24        // prev now points to the head of the reversed second half
25        
26        // 3. Track the maximum twin sum by iterating through both halves
27        int maxVal = 0;
28        ListNode* firstHalf = head;
29        ListNode* secondHalf = prev;
30        
31        while (secondHalf != nullptr) {
32            int currentTwinSum = firstHalf->val + secondHalf->val;
33            maxVal = max(maxVal, currentTwinSum);
34            firstHalf = firstHalf->next;
35            secondHalf = secondHalf->next;
36        }
37        
38        return maxVal;
39    }
40};
41