// isproblem ko solve karne ka 4 se 5 approaches hai 

// floyd cycle detection algorithm 
// Time complexity O(N) and space complexity O(1) 
Node *removeLoop(Node *head)
{
    if(head == NULL) return head ;
    Node* slow = head ;
    Node* fast = head ;
    bool fang = true ;
    while(slow != NULL && fast != NULL){
        Node* temp = fast ;
        fast = fast->next ;
        slow = slow->next ;

        if(fast != NULL && fang) fast = fast->next ;
        // detecting the loop in the linked list
        if(slow == fast && fang){
            fang = false ;
            slow = head ;
            // if fast and slow pointer meet on head for the first time
            temp = temp->next ;
        }
        // removing loop in the linked list
        if(!fang && slow == fast){
            temp->next = NULL ;
            break ;
        }    
    }
    return head ;
}

// using set (storing the addresses of each node and if we encounter the same address that means loop is present)
// Time complexity O(NlogN) and space complexity O(N)
Node *removeLoop(Node *head)
{
    Node* tail = head ;
    if(head == NULL) return head ;
    set<Node*> s ;
    while(tail != NULL){
        if(s.find(tail->next) != s.end()){
            tail->next = NULL ;
        }
        s.insert(tail) ;
        tail = tail->next ;
    }
    return head ;
}

// using map (storing the addresses of each node and marking it as try if we encounter that node again that is marked true means loop is present)
// Time complexity O(N) and space complexity O(N)
Node *removeLoop(Node *head)
{
    Node* tail = head ;
    if(head == NULL) return head ;
    map<Node*,bool> mp ;
    while(tail != NULL){
        
        if(mp[tail->next]){
            tail->next = NULL ;
        }
        mp[tail] = true ;
        tail = tail->next ;
    }
    return head ;
}

