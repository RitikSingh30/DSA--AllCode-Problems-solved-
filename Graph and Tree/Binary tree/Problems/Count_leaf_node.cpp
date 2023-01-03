/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/

void inOrder_Traversal(BinaryTreeNode<int> *root , int& count){
    if(root == NULL) return ;
    inOrder_Traversal(root->left,count) ;
    if(root->left == NULL && root->right == NULL) count++ ;
    inOrder_Traversal(root->right,count) ;
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0 ;
    inOrder_Traversal(root,count) ;
    return count ;
}