// In this algorith we will detect the loop in the linked list using floyd and also going to remove the loop 
#include<iostream>
#include<set>
using namespace std ;

class Node{
    public:
        int data ;
        Node* next ;

        Node(int data){
            this->data = data ;
            this->next = NULL ;
        }
};

void insert(Node* &head , Node* &tail,int data){
    Node* node = new Node(data) ;

    if(head == NULL){
        head = node ;
        tail = node ;
    }
    else{
        tail->next = node ;
        tail = node ;
    }
}

void print(Node* &head,Node* &tail, int k){
    Node* temp = head ;
    set<Node*> s ;
    int cnt = 1 ;
    while(temp != NULL){
        // creating a cycle at certain position
        cout << temp->data << ' ' ;
        if(cnt == k) tail->next = temp ; 
        // if cycle is present then break the loop 
        if(s.find(temp) != s.end()) break ;
        s.insert(temp) ;
        temp = temp->next;
        cnt++ ;
    }
    cout << endl ;
}

// detecting if cycle is present or not 
Node *floydDetec(Node *head)
{
    if(head == NULL) return head ;
    Node* slow = head ;
    Node* fast = head ;

    while(slow != NULL && fast != NULL){
        fast = fast->next ;
        slow = slow->next ;

        if(fast != NULL) fast = fast->next ;
        // Cycle is present 
        if(slow == fast) return slow ;
    }
    // Cycle is not present 
    return NULL ;
}

Node* gettingStartingNodeOfCycle(Node* head){
    
    Node* intersection = floydDetec(head) ;
    // no cycle is present
    if(intersection == NULL) return NULL ;
    Node* slow = head ;
    
    while(slow != intersection){
        slow = slow->next ;
        intersection = intersection->next ;
    }

    return slow ;
}

Node* removeLoop(Node* head){
    Node* startOfloop = gettingStartingNodeOfCycle(head) ;

    // cycle is not present 
    if(startOfloop == NULL) return head ;
    Node* temp = startOfloop ;

    while(temp->next != startOfloop){
        temp = temp->next ;
    }
    temp->next = NULL ;
    return head ;
}

int main(){
    int n , k ;
    cin >> n >> k ;

    Node* head = NULL ;
    Node* tail = NULL ;

    for(int i = 0 ; i < n ; i++){
        int x ;
        cin >> x ;
        insert(head,tail,x) ;
    }

    print(head,tail,k) ;
    removeLoop(head) ;
    
}