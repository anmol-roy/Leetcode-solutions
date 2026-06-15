// Last updated: 15/06/2026, 08:51:28
1class Solution {
2public:
3    ListNode* deleteMiddle(ListNode* head) {
4        // Corrected base case: do NOT manually delete head here
5        if (head == NULL || head->next == NULL) {
6            return NULL; 
7        }
8
9        ListNode* slow = head;
10        ListNode* fast = head;
11        ListNode* prev = NULL;
12
13        while (fast != NULL && fast->next != NULL) {
14            prev =  slow;
15            slow =    slow->next;
16            fast = fast->next->next;
17        }
18
19        prev->next = slow->next;
20        delete slow; // This delete is correct because this node is now unlinked
21
22        return head;
23    }
24};
25