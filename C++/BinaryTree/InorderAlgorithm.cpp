//Inorder Algorithm
#include <iostream>
using namespace std;

//Defining Tree
struct Tree{
    int key;
    Tree *left,*right;
    Tree(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};

void inorder(Tree *root){

    if(root->left==NULL || root->right==NULL ){
    if(root->left!=NULL)
    cout<<root->left->key<<endl;
    cout<<root->key<<endl;
    if(root->right!=NULL)
    cout<<root->right->key<<endl;
    return;
    }
    inorder(root->left);
    cout<<root->key<<endl;
    inorder(root->right);
}



int main() {

    Tree *root=new Tree(10);
    root->left=new Tree(20);
    root->right=new Tree(30);
    root->left->left=new Tree(40);
    root->left->right=new Tree(50);
    root->left->right->left=new Tree(70);
    root->left->right->right=new Tree(80);
    root->right->right=new Tree(60);
    inorder(root);


return 0;
}