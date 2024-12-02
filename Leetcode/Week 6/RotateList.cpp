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
        if(!head || !head->next)
            return head;
        ListNode *temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        k = k % len;
        if(!k)
            return head;
        int i = len - k;
        temp = head;
        while(--i > 0)
            temp = temp->next;
        ListNode *temp2 = temp->next, *temp3 = temp->next;
        temp->next = nullptr;
        while(temp2->next)
            temp2 = temp2->next;
        temp2->next = head;
        return temp3;
    }
};