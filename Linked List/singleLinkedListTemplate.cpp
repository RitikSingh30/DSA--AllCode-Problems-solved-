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

void print(Node* &head,Node* &tail){
    Node* temp = head ;
    while(temp != NULL){
        cout << temp->data << ' ' ;
        temp = temp->next ;
    }
    cout << endl ;
}

int main(){
    int n , k ;
    cin >> n ;

    Node* head = NULL ;
    Node* tail = NULL ;

    for(int i = 0 ; i < n ; i++){
        int x ;
        cin >> x ;
        insert(head,tail,x) ;
    }
}