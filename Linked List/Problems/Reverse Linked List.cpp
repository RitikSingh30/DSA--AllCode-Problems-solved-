#include<iostream>
using namespace std ;

// iterative solution 
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* prev = NULL ;
    LinkedListNode<int>* temp = head ;
    while(temp != NULL){
        LinkedListNode<int>* forward = temp->next ;
        temp->next = prev ;
        prev = temp ;
        temp = forward ;
    }  
    return prev ;
}

// recursive solution 
LinkedListNode<int>* reverseLink(LinkedListNode<int>* &head, LinkedListNode<int>* &prev){
    if(head == NULL) return prev ;

    LinkedListNode<int>* forward = head->next ;
    head->next = prev ;
    prev = head ;
    head = forward ;

    return reverseLink(head,prev) ;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* prev = NULL ;
    return reverseLink(head,prev) ;
}

int main(){
    LinkedListNode<int>* head = NULL ;
    return 0 ;
}