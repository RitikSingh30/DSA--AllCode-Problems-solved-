#include <iostream>
#include <queue>
using namespace std ;

// creation of a node 
class node{
    public:
        int data ;
        node* left ;
        node* right ;

        node(int d){
            this->data = d ;
            this->right = NULL ;
            this->left = NULL ;
        }
};

// creation of binary tree 
node* builtTree(node* root){
    cout << "Enter the data: " << endl ;
    int data ;
    cin >> data ;
    root = new node(data) ;
    
    if(data == -1){
        return NULL ;
    }

    cout << "Enter data for inseting in left of " << data << endl ;
    root->left = builtTree(root->left) ;
    cout << "Enter data for inserting in right of " << data << endl ;
    root->right = builtTree(root->right) ;
    return root ;
}

// level order traversal in binary tree
void level_order_traversal(node* root){
    // level order traversal is also know as breath first search(bfs) 
    // to run bfs we make use of queue
    queue<node*> q ;
    q.push(root) ;
    // yaha hume pata tha ki first level me ek hi node hota hai isliye usse dalne ke baad humne turant null ko push kar diya queue me
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front() ;
        q.pop() ;
        /* ab humne apna level order traversal to sahi se kar liye but hume yaha pe ek changes karna hai ki jab bhi koi bhi level complete 
            ho uske baad ek endl print ho jisse hume pata chalega ki ek level complete ho chuka hai and ye karne ke liye hume ek seprator use 
            karna hoga jiski madat se hum ye endl wala kaam kar payenge 
        */
        if(temp == NULL){ // level has been completed 
            cout << endl ;
            if(!q.empty()) // abhi agae aur level bacha hua hai to unhe separate karne ke liye NULL ki jarurat hai
                q.push(NULL) ;
        }
        else{
            /* ye temp-> data ko hume else part me isliye likha hai because agar temp null hua to uska koi data present nahi hoga to agar
                koi data present nahi hai and phir bhi hum usse print kara rhe hai to segmentation fault aayega 
            */
            cout << temp->data << ' ' ;
            if(temp->left) 
                q.push(temp->left) ;

            if(temp->right)
                q.push(temp->right) ;
        }
    }
}

int main(){
    node* root = NULL ;
    
    // Creating a tree 
    // tree data = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = builtTree(root) ;
    level_order_traversal(root) ;

    return 0 ;
}