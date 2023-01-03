#include<iostream>
using namespace std ;	

class node{
	public:
		int data ;
		node* next ;

		// constructor 
		node(int data){
			this->data = data ;
			this->next = NULL ;
		}

		// destructor 
		~node(){
			int value = this->data ;
			// memory free 
			if(this->next != NULL){
				delete next ;
				this->next = NULL ;
			}

			cout << "Memory free for node with data " << value << endl ;
		}
};

// Inserting node at front
void InsertAtHead(node* &head , node* &tail , int data){

    // new node created 
	node* node1 = new node(data) ;
	// if list is empty 
    if(head == NULL){
        head = node1 ;
        tail = node1 ;
        return ;
    }
	node1->next = head ;
	head = node1 ;
}

// Inserting node at back 
void InsertAtTail(node* &head , node* &tail , int data){

    // new node created 
	node* node1 = new node(data) ;
	if(head == NULL){
		head = node1 ;
		tail = node1 ;
	}
	else{
		tail->next = node1 ;
		tail = node1 ;
	}
}

// Inserting element at the given position  
void InsertAtPosition(node* &head , node* &tail , int data , int index){

	if(index == 0){
		InsertAtHead(head,tail,data) ;
		return ;
	}

	node* temp = head ;
	int cnt = 0 ;
	while(cnt < index - 1){
		temp = temp->next ;
		cnt++ ;
	}

	if(temp->next == NULL){
		InsertAtTail(head,tail,data) ;
		return ;
	}
	
	node* node1 = new node(data) ;
	node1->next = temp->next ;
	temp->next = node1 ;	
}

// deleting the node 
void deletenode(node* &head , int position , node* &tail){

	// handling edge case for head node because in head node previous pointer is null 
	if(position == 1){

		node* temp = head ;
		head = head->next ;
		temp->next = NULL ;
		delete temp ;
	}
	else{

		node* cur = head ;
		node* prev = NULL ;

		int cnt = 1 ;
		while(cnt < position){
			// cout << prev->next << endl ;
			prev = cur ;
			// prev->next = head ;
			cur = cur->next ;
			cnt++ ;
		}

		if(cur->next == NULL){
			tail = prev ;
		}

		prev->next = cur->next ;
		cur->next = NULL ;
		delete cur ;
	}
}

// Printing the node 
void print(node* &head){

	// coping the head node to temp variable so that the value of head should not be changed 
	node* temp = head ;
	while(temp != NULL){
		cout << temp->data << ' ' ;
		temp = temp->next ;
	}
	cout << endl ;
}

int main(){

	node* head = NULL ;
	node* tail1 = NULL ;
	InsertAtHead(head,tail1,20) ;
	InsertAtHead(head,tail1,21) ;
	InsertAtHead(head,tail1,22) ;

	print(head) ;

	node* head1 = NULL ;
	node* tail = NULL ;
	InsertAtTail(head1,tail,20) ;
	InsertAtTail(head1,tail,21) ;
	InsertAtTail(head1,tail,22) ;

	print(head1) ; 

	InsertAtPosition(head1,tail,23,3) ;
	print(head1) ;

	// cout << head1->data << endl ;
	// cout << tail->data << endl ;

	deletenode(head1,4,tail) ;
	print(head1);
	cout << tail->data << endl ;

	return 0 ;
}
