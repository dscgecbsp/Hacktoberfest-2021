public class LinkedList {
    public static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static Node head;
    public static Node tail;
    public static int size;

    // Methods
    // 1:-- AddFirst()
    public void addFirst(int data) {
        // creating new node.
        Node newNode = new Node(data);
        size++;

        // if head has a null value
        if (head == null) {
            head = tail = newNode;
            return;
        }

        // pointing to head
        newNode.next = head;

        // making new node a head node
        head = newNode;
    }

    // 2:-- AddLast()
    public void addlast(int data) {
        Node newNode = new Node(data);
        size++;
        if (head == null) {
            head = tail = newNode;
            return;
        }
        tail.next = newNode;
        tail = newNode;
    }

    // 3:-- print()
    public void print() {
        if (head == null) {
            System.out.println("Head is empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public void add(int idx, int data) {
        if (idx == 0) {
            addFirst(data);
            return;
        }
        Node newnode = new Node(data);
        size++;
        Node temp = head;
        int i = 0;
        while (i < idx - 1) {
            temp = temp.next;
            i++;
        }
        newnode.next = temp.next;
        temp.next = newnode;
    }

    // Removing First Element
    public int removefirst() {
        if (size == 0) {
            System.out.print("node is Empty");
            return Integer.MIN_VALUE;
        } else if (size == 1) {
            int val = head.data;
            head = tail = null;
            size = 0;
            return val;
        }
        int val = head.data;
        head = head.next;
        size--;
        return val;
    }

    // Removing Last Element
    public int removelast() {
         if (size == 0) {
             System.out.print("node is Empty");
             return Integer.MIN_VALUE;
         } else if (size == 1) {
             int val = head.data;
             head = tail = null;
             size = 0;
             return val;
         }
        Node prev = head;
        for (int i = 0; i < size-2; i++) {
            prev = prev.next;
        }
        int val = tail.data;
        prev.next = null;
        tail = prev;
        size--;
        return val;
    }
    // reverse a linkd List
    public void reverse(){
        Node prev = null;
        Node curr = tail = head;          // 1 --> 2 --> 3 --> 4 --> 5 --> null
        Node next;                        //  
        while(curr != null){
            next = curr.next;
            curr.next = prev;
            prev =curr;
            curr =next;
        }
        head = prev;
    }
    // Remove nth element from last
    public void delete(int n){
        int sz = 0;
        Node temp = head;
        while(temp != null){
            temp = temp.next;
            sz++;
        }

        if(n == sz){
            head = head.next;
            return;
        }
        Node prev = head;
        for(int i =1; i < sz-n; i++){
            prev = prev.next;
        }
        prev.next = prev.next.next;
        return;
    }
    public Node findMid(Node head){
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

// cHECK Pallindrome
    public boolean checkPallindrome(){
        if(head == null ||head.next == null){
            return true;
        }
        //find mid
        Node midnode = findMid(head);
        // reverse the half LL
        Node prev = null;
        Node curr = midnode;
        Node next;
        while(curr != null){
             next = curr.next;
             curr.next = prev;
             prev = curr;
             curr = next;
        }
        // comp left part and rigth part
        Node right = prev;
        Node left = head;
        while(right != null){
            if(right.data != left.data){
                return false;
            }
            right = right.next;
            left = left.next;
        }
        return true;
    }

    // To check the LL is cyclic or not
    public static boolean cyclic(){
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }

    // Removing Cycle in LL
    public static void removecyclic(){
        Node slow = head;
        Node fast = head;
        boolean Cycle = false;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                Cycle = true;
                break;
            }
        }

        // if LL is not cyclic
        if(Cycle = false){
            return;
        }
        //Finding Meeting point
        slow = head;
        Node prev = null;
        while(slow != fast){
            prev = fast;
            slow = slow.next;
            fast = fast.next;
        }
        // removing cycle
        prev.next = null;
    }

    public static void main(String[] args) {
        // LinkedList ll = new LinkedList();
        // ll.addFirst(2);
        // ll.addFirst(1);
        // ll.addlast(3);
        // ll.addlast(4);
        // ll.add(2, 6);
        head = new Node(1);
        Node temp = new Node(2);
        head.next = temp;
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = temp;
        System.out.println(cyclic());
        removecyclic();
        System.out.println(cyclic());

        // ll.print();
        // ll.removefirst();
        // ll.print();
        // ll.removelast();
        // ll.print();
        // System.out.println(size);
        // ll.reverse();
        // ll.print();
        // ll.delete(4);
        // ll.print();
    //   System.out.println(ll.checkPallindrome());
    }
}
