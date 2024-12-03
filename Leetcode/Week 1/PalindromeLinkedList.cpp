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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        if(!head->next->next) return head->val == head->next->val;

        //finding middle of the Llist.

        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow;
        ListNode *prev = nullptr; 
        ListNode *next = nullptr; 

        while(mid!=nullptr){
            next=mid->next;
            mid->next=prev;
            prev=mid;
            mid = next;

        }
        while(prev){
            if(head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;

        }       
        return true;
    }
};