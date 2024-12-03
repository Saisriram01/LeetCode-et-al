#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode temp;
        temp.next = head;
        ListNode *prev = &temp; 
        ListNode *curr = head;

        // Counting the total number of nodes in the list so we can divide into k sized groups
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        while (count >= k) {
            curr = prev->next;
            ListNode *next = curr->next;
            //reversing the subarray of size k
            int i = 1;
            while(i < k){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
                i++;
            }
            // setting pointers for the next k group
            prev = curr;
            count -= k;
        }

        return temp.next;
    }
};