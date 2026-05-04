// Last updated: 04/05/2026, 15:44:49
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp = new ListNode(-1);
        ListNode *dummy = temp;
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        while(head1 != NULL && head2 != NULL){
            if(head1->val < head2->val){
                dummy->next = head1;
                head1=head1->next;
            } else {
                dummy->next = head2;
                head2 = head2->next;
            }
            dummy = dummy->next;
        }
        if(head1) {
            dummy->next = head1;
        } else {
            dummy->next = head2;
        }
        return temp->next;

    }
};