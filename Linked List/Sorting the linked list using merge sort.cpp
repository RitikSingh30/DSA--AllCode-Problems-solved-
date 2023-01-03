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

Node* merge(Node*& firstPartHead , Node*& SecondPartHead){
    Node* newHead = NULL ;
    // base case if one of the node is NULL 
    if(firstPartHead == NULL) return SecondPartHead ;
    else if(SecondPartHead == NULL) return firstPartHead ;

    // set the first node as head and recursive call for the next node
    if(firstPartHead->data <= SecondPartHead->data){
        newHead = firstPartHead ;
        newHead->next = merge(firstPartHead->next,SecondPartHead) ;
    }
    // set the second node as head and recursive call for the next node
    else{
         newHead = SecondPartHead ;
        newHead->next = merge(firstPartHead,SecondPartHead->next) ;
    }
    // return the new head 
    return newHead ;
}

Node* mergeSort(Node*& head){
    // for finding the mid of linked list we will make use of fast pointer and slow pointer we will move fast pointer by 2 steps and slow
    // pointer by one steps if fast pointer reaches the NULL then the slow pointer is pointing to the mid of the linked list 

    // Base case for 0 or 1 node 
    if(head == NULL || head->next == NULL) return head ;
    if(head->next->next == NULL){
        Node* secondHalfHead = head->next ;
        head->next = NULL ;
        return merge(head,secondHalfHead) ;
    }

    Node* fast = head->next ;
    Node* slow = head ;

    // finding the midpoint of the range 
    while(fast != NULL){
        fast = fast->next ;
        if(fast != NULL){
            fast = fast->next ;
            slow = slow->next ;
        }
    }

    // making the secondhalfhead as slow pointer next because slow pointer is pointing to the mid 
    Node* secondHalfHead = slow->next ;
    // making slow pointer next as NULL 
    slow->next = NULL ;

    Node* first = mergeSort(head) ;
    Node* second = mergeSort(secondHalfHead) ;
    // merging two linked list 
    return merge(first,second) ;
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
    
    head = mergeSort(head) ;
    print(head,tail) ;
}