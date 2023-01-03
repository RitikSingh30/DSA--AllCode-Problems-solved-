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

/* yaha pe humne node* root ko by reference function ko pass kiya hai because hume uski copy function ko pass nahi karna tha
    agar copy pass karte to jo bhi hum tree construct karte iss root node ki help se to original root node me nahi hoti isliye humne isse
    by reference pass kiya hai
*/
void creating_tree_from_level_order_traversal(node* &root){
    queue<node*> q ;
    int data ;
    cout << "Enter the data for root node " << endl ;
    cin >> data ;
    root = new node(data) ;
    q.push(root) ;
    while(!q.empty()){
        auto temp = q.front() ;
        q.pop() ;

        cout << "Enter the data of left node of " << temp->data << endl;
        int leftdata; 
        cin >> leftdata ;
        if(leftdata != -1){
            temp->left = new node(leftdata) ;
            q.push(temp->left) ;
        }

        cout << "Enter the data of right node of " << temp->data << endl;
        int rightdata; 
        cin >> rightdata ;
        if(rightdata != -1){
            temp->right = new node(rightdata) ;
            q.push(temp->right);
        }
    }
}

int main(){
    node* root = NULL ;
    
    // Creating a tree 
    // tree data = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    creating_tree_from_level_order_traversal(root) ;
    level_order_traversal(root) ;

    return 0 ;
}