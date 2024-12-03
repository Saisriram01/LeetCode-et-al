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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        if (!head || !head->next)
            return nullptr;
        struct ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        cout<<count;
        temp = head;
        for(int i = (count - n-1);i>0;i--)
            temp = temp->next;
        
        if (n == count)
            head = temp->next;
        else if(n>1)
            temp->next = temp->next->next;
        else
            temp->next = nullptr;
        return head;
    }
};