#include<iostream>
using namespace std ;

class node{
    public:
        int data ;
        node* next ; 
        node* prev ;

        node(int data){
            this->data = data ;
            prev = NULL ;
            next = NULL ;
        }
};

void insert(node* &head,node* &tail,int data){
    node* temp = new node(data) ; 

    if(head == NULL){
        head = temp ;
        tail = temp ;
    }
    else{
        temp->prev = tail ;
        tail->next = temp ;
        tail = temp ;
    }
}

void print(node* head){
    node* temp = head ;
    node* temp_rev = NULL ;

    cout << "Printing the linked list in Straight Order" << endl ;
    while(temp != NULL){
        cout << temp->data << ' ' ;
        if(temp->next == NULL) temp_rev = temp ;
        temp = temp->next ;
    }
    cout << endl ;
    
    cout << "Printing the linked list in reverse order using previous pointer" << endl ;
    while(temp_rev != NULL){
        cout << temp_rev->data << ' ' ;
        temp_rev = temp_rev->prev ;
    }
    cout << endl ;
}

node* merge(node* &head, node* &right){

    if(head == NULL) return right ;
    else if(right == NULL) return head ;

    if(head->data <= right->data){
        head->next = merge(head->next,right) ;
        if(head->next != NULL) head->next->prev = head ;
        return head ;
    }
    else{
        right->next = merge(head,right->next) ;
        if(right->next != NULL) right->next->prev = right ;
        return right ;
    }
}

void mergeSort(node* &head){
    
    if(head == NULL || head->next == NULL) return ;
    node* slow = head ;
    node* fast = head->next ;

    while(fast != NULL){
        fast = fast->next ;
        if(fast != NULL){
            fast = fast->next ;
            slow = slow->next ;
        }
    }

    node* right = slow->next ;
    slow->next = NULL ;
    right->prev = NULL ;

    mergeSort(head) ;
    mergeSort(right) ;

    head = merge(head,right) ;
}


int main(){
    node* head = NULL ;
    node* tail = NULL ;

    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int x ;
        cin >> x ;
        insert(head,tail,x) ;
    }    

    print(head) ;
    mergeSort(head) ;
    print(head) ;
    return 0 ;
}