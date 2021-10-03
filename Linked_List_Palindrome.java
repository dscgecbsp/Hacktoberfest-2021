class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode node1 = head, node2 = head;
        int len = 0;
        
        // to know the length
        while(node2 != null){
            ++len;
            node2 = node2.next;
        }
        
        
        // go till mid
        node2 = head; 
        int half = len/2;
        for(int i = 0; i < half; i++)
            node2 = node2.next;
        
        
        
        // reverse second mid
        ListNode prev = null, curr = node2, next = node2.next;
        while(next != null){
            curr.next = prev;
            prev = curr;
            curr = next;
            next = curr.next;
        }
        
        
        
        // check first half and second half are equal
        curr.next = prev;
        while(curr != null){
            if(curr.val != head.val)
                return false;
            curr = curr.next;
            head = head.next;
        }
        
        
        return true;
    }
}
