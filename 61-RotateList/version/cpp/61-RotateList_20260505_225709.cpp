// Last updated: 05/05/2026, 22:57:09
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* rotateRight(ListNode* head, int k) {
14        // Handle empty list or single-node list
15        if (!head || !head->next || k == 0) return head;
16
17        // 1. Calculate the length of the list and find the tail
18        ListNode* tail = head;
19        int length = 1;
20        while (tail->next) {
21            tail = tail->next;
22            length++;
23        }
24
25        // 2. Adjust k to handle rotations larger than list length
26        k = k % length;
27        if (k == 0) return head;
28
29        // 3. Make the list circular
30        tail->next = head;
31        // 4. Find the new tail: it is at (length - k) steps from the current head
32        // or (length - k - 1) steps if starting from the head.
33        ListNode* newTail = head;
34        for (int i = 0; i < length - k - 1; i++) {
35            newTail = newTail->next;
36        }
37
38        // 5. Set the new head and break the circular link
39        ListNode* newHead = newTail->next;
40        newTail->next = nullptr;
41
42        return newHead;
43    }
44};
45        
46