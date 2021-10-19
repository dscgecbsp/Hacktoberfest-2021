//Leetcode problem : Odd Even Linked List ( https://leetcode.com/problems/odd-even-linked-list/ )

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* h = head;
        ListNode* nhead = even;
        
        while(even != NULL && even->next != NULL){
            ListNode* f = even->next;
            odd->next = f;
            even->next = f->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = NULL;
        odd->next = nhead;
        return h;
    }
};
