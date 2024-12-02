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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *>out;
        int len = 0;
        ListNode *temp = head, *head_temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }

        int x = len % k, y = len / k;
        if(!y){
            ListNode *t;
            while(head){
                    out.push_back(head);
                    t = head->next;
                    head->next = nullptr;
                    head = t;     
               }
               cout<<x<<endl;
               while( x++ < k)
                    out.push_back(nullptr);
                return out;
            }
    
        while(k-- > 0){
            ListNode *temp = head_temp;
            int noofnodes = y + (1?x>0:0);
            x--;
            cout<<noofnodes<<endl;
            while(noofnodes-- > 1){
                temp = temp->next;
            }
            out.push_back(head_temp);
            if(temp->next){
                ListNode *t = temp->next;
                temp->next = nullptr;
                head_temp = t;
            }
        }

        return out;
    }
};