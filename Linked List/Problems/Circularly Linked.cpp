bool isCircular(Node* head){
    Node* tail = head ;
    if(head == NULL) return true ;
    set<Node*> s ;
    while(tail != NULL){
        if(s.find(tail) != s.end()) return true ;
        s.insert(tail) ;
        tail = tail->next ;
    }
    return false ;
}