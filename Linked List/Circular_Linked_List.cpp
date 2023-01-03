// implementing circular linked list on singly linked list 
// we can also create a circular doubly linked list 

#include<iostream>
using namespace std ;

class node{
    public:
        int data ;
        node* next ;

        node(int data){
            this->data = data ;
            this->next = NULL ;
        }

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

// circular linked list me hume head pointer ki need nahi hoti hai sirf tail pointer se kaam chal jata hai because tail pointer se hum last me bhi insert kar sakte hai and tail pointer ka hi use kar ke hum head pe bhi insert kar sakte hai
// now ab humari jo list hai wo to circular hai to hume pata hi nahi hai ki node ka starting point kaunsa hai and ending point kaunsa hai to hum data ke hisab se node ko insert karege like hume input me ek data milega hum check karege ki kaunse data ke aage iss data ko dalna hai and waha pe jake isse place kar denge

// Inserting node at front
void insertingNode(node* &tail, int element , int data){

    // empty list 
    if(tail == NULL){
        node* newNode = new node(data) ;
        tail = newNode ;
        newNode->next = newNode ;
        return ;
    }

    // non - empty list 
    // assuming that the element is present in the list 

    node* curr = tail ;

    while(curr->data != element){
        curr = curr->next ;
    }

    // element found -> curr is representing element wala node 
    node* temp = new node(data) ;
    temp->next = curr->next ;
    curr->next = temp ;

}

// deleting node 
void deleteNode(node* &tail , int value){

    // empty list 
    if(tail == NULL){
        cout << "List is empty please check again " << endl ;
        return ;
    }

    // non - empty list 
    // assuming that value is present in the list 

    node* prev = tail ;
    node* cur = prev->next ;

    while(cur->data != value){
        prev = cur ;
        cur = cur->next ;
    }

    // 1 node linked list
    if(cur == prev){
        tail = NULL ;
        return ;
    }

    // >= 2 node linked list 
    if(tail == cur){
        tail = prev ;
    }
    prev->next = cur->next ;
    cur->next = NULL ;
    delete cur ;
}

// Printing the node
void print(node* tail){
    
    // empty list
    if(tail == NULL){
        cout << "List is empty" << endl ;
        return ;
    }

    node* temp = tail ;
    do
    {
        cout << tail->data << ' ' ;
        tail = tail->next ;
    } while (tail != temp);

    cout << endl ;
}

int main(){
    
    node* tail = NULL ;

    // empty list me insert kar rhe hai 
    insertingNode(tail,5,3) ;
    print(tail) ;
    
    insertingNode(tail,3,5) ;
    print(tail) ;
    insertingNode(tail,5,1) ; 
    print(tail) ;
    cout << tail->data << endl ;
    cout << tail->next->data << endl ;

    insertingNode(tail,1,7) ;
    print(tail) ;
    insertingNode(tail,5,2) ;
    print(tail) ;

    deleteNode(tail,3) ;
    print(tail) ;

    return 0 ;
}