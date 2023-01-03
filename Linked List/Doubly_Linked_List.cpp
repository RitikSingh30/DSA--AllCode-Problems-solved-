#include<iostream>
using namespace std ;

class node{
    public:
        int data ;
        node* prev ;
        node* next ;

    node(int data){
        this->data = data ;
        this->prev = NULL ;
        this->next = NULL ;
    }

    ~node(){
        cout << "deleting node with data : " << this->data << endl ;

        // making the previous pointer of the next data to point to NULL 
        if(this->next != NULL){
            this->next->prev = NULL ;
        }

        this->prev = NULL ;
        this->next = NULL ;
    }
};

// Printing Doubly Linked List 
void print(node* head){
    node* temp = head ;
    while(temp != NULL){
        cout << temp->data << ' ' ;
        temp = temp->next ;
    }
    cout << endl ;
}

// Getting the length of Double linked list 
int getLength(node* head){
    int len = 0 ;
    node* temp = head ;
    while(temp != NULL){
        len++ ;
        temp = temp->next ;
    }
    return len ;
}

// Inserting at head 
void insertAtHead(node* &head , node* &tail , int data){

    // Empty list 
    if(head == NULL){
        node* temp = new node(data) ;
        head = temp ;
        tail = temp ;
        return ;
    }

    node* node1 = new node(data) ;
    node1->next = head ;
    head->prev = node1 ;
    head = node1 ;
}

// Inserting at Tail 
void insertAtTail(node* &head , node* &tail, int data){

    // Empty list 
    if(tail == NULL){
        node* temp = new node(data) ;
        tail = temp ;
        head = temp ;
        return ;
    }

    node* node1 = new node(data) ;
    tail->next = node1 ;
    node1->prev = tail ;
    tail = node1 ; 
}

void insertAtAnyPosition(node* &head , node* &tail , int data , int pos){

    // Inserting at start
    if(pos == 1){
        insertAtHead(head,tail,data) ;
        return ;
    
    }

    node* temp = head ;
    int cur = 1 ;

    while(cur < pos - 1){
        temp = temp->next ;
        cur++ ;
    }

    if(temp->next == NULL){
        insertAtTail(head,tail,data) ;
        return ;
    }

    node* node1 = new node(data) ;
    
    // (*(*temp).next).prev = temp->next->prev (done ka same matlab hai)
    temp->next->prev = node1 ;
    node1->next = temp->next ;
    temp->next = node1 ;
    node1->prev = temp ;

}

void deletenode(node* &head , node* &tail , int pos){

    node* temp = head ;
    if(pos == 1){
        head = head->next ;
        // jab hum delete temp karte hai to wo sirf temp class me jo data naam ka variable hai usse value delete karta hai (agar humne apna custome destructor nahi likha to wo aise behave karta hai) temp class me jo next and prev pointer hai wo as it rehte hai matlab wo log jisko point kar rhe hai usko hi point karte hai delete karne ke baad bhi 
        delete temp ;
        return ;
    }

    int cnt = 1 ;
    while(cnt < pos){
        temp = temp->next ;
        cnt++ ;
    } 

    if(temp->next == NULL){
        tail = temp->prev ;
        tail->next = NULL ;
        delete temp ;
        return ;
    }

    temp->prev->next = temp->next ;
    temp->next->prev = temp->prev ;
    delete temp ;

}

int main(){
    node* head = NULL ;
    node* tail = NULL ;

    cout << getLength(head) << endl ;

    insertAtHead(head,tail,11) ;
    insertAtHead(head,tail,13) ;
    insertAtHead(head,tail,8) ;
    print(head) ;

    insertAtTail(head,tail,25) ;
    print(head) ;
    cout << tail->data << endl ;

    insertAtAnyPosition(head,tail,15,3) ;
    print(head) ;
    insertAtAnyPosition(head,tail,14,1) ;
    print(head) ;
    cout << head->data << endl ;
    insertAtAnyPosition(head,tail,12,7) ;
    print(head) ;
    cout << tail->data << endl ;

    deletenode(head,tail,1) ;
    print(head) ;
    deletenode(head,tail,6) ;
    print(head) ;
    cout << tail->data << endl ;
    deletenode(head,tail,3) ;
    print(head) ;
    
    return 0 ;
}