// Approach 1 iterative solution 
Node *findMiddle(Node *head) {
    int noOfNode = 0 ;
    Node* temp = head ;

    while(temp != NULL){
        noOfNode++ ;
        temp = temp->next ;
    }

    int cnt = noOfNode / 2 + 1 ;
    int in = 1 ;
    while(in < cnt){
        head = head->next ;
        in++ ;
    }

    return head ;
}

// Approach 2 iterative solution 
Node *findMiddle(Node *head) {
    // base case 
    if(head == NULL || head->next == NULL) return head ;
    else if(head->next->next == NULL) return head->next ;
    Node* player1 = head ;
    Node* player2 = head->next ;
    while(player2 != NULL){
        player1 = player1->next ;
        player2 = player2->next ;
        if(player2 != NULL) player2 = player2->next ;
        else break ;
    }

    return player1 ;
}