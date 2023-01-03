#include <iostream>
#include<queue>
using namespace std ;

class node{
    public:
    int data ;
    node* left ;
    node* right ;
        node(int data){
            this->data = data ;
            left = NULL ;
            right = NULL ;
        }
};

node* construct_tree(node* root){
    int data ;
    cout << "Enter the value of the node" << endl ;
    cin >> data ;
    root = new node(data) ;
    if(data == -1){
        return NULL ;
    }
    cout << "Enter the value of the left part of" << data << endl;
    root->left = construct_tree(root->left) ;
    cout << "Enter the value of Right part of" << data << endl;
    root->right = construct_tree(root->right) ;
    return root ;
}

// root left right
// in this way we print the element of the tree in preorder traversal
void preorder_traversal(node* root){
    if(root == NULL) 
        return ;
    cout << root->data << ' ' ;
    preorder_traversal(root->left) ;
    preorder_traversal(root->right) ;
}

int main(){
    node* root = NULL ;
    root = construct_tree(root) ;
    preorder_traversal(root) ;
}