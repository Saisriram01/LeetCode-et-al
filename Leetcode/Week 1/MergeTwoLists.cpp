/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->next = NULL;
    struct ListNode* merged_list = temp;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            merged_list->next = l1;
            l1 = l1->next;
        } else {
            merged_list->next = l2;
            l2 = l2->next;
        }
        merged_list = merged_list->next;
    }
    if (l1 != NULL) {
        merged_list->next = l1;
    } else {
        merged_list->next = l2;
    }
    return temp->next;
    
}