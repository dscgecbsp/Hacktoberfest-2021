import java.util.*;

class Solution{
    static Node root;
    static ArrayList<Integer> arr = new ArrayList<>();

    // Create Class Node
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int d){
            data = d;
            left = null;
            right = null;
        }
    }

    // Function to insert new element
    static Node insertion(Node node,int item){
        if(node == null){
            node = new Node(item);
            return node;
        }
        else if(item < node.data){
            node.left = insertion(node.left, item);
        }
        else if(item > node.data){
            node.right = insertion(node.right, item);
        }
        return node;
    }

    // Function to traverse inorder
    static void inOrder(Node node){
        if(node != null){
            inOrder(node.left);
            arr.add(node.data);
            inOrder(node.right);
        }
    }

    // Driver function
    public static void main(String[] args) {
        root = insertion(root,22);
        insertion(root,5);
        insertion(root,69);
        insertion(root,2);
        inOrder(root);
        System.out.println("MIN = "+arr.get(0));
        System.out.println("MAX = "+arr.get(arr.size()-1));
    }
}