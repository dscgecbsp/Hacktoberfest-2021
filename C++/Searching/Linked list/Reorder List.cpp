// leetcode problem : Reorder List ( https://leetcode.com/problems/reorder-list/ )

class Solution {
public:
    
     ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head, *fast =head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL, *curr = head;
        
        while(curr != NULL){
            ListNode* f = curr->next;
            curr->next = prev;
            prev = curr;
            curr = f;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return;
        
        ListNode* p1 = head;
        
        ListNode* mid = middleNode(head);
        
        ListNode* p2 =  mid->next;
        mid->next = NULL;
        
        p2 = reverseList(p2);
        
        while(p2 != NULL){
            ListNode* c1 = p1->next;
            ListNode* c2 = p2->next;
            
            p1->next = p2;
            p2->next = c1;
            
            p1 = c1;
            p2 = c2;
        }
        
        return;
    }
    
};
