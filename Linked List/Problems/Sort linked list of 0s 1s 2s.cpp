// count the number of 0's , 1's and 2's and then put all the 0's first then all the 1's then all the 2's 
// Time complexity O(N) , space complexity O(1)
Node* sortList(Node *head)
{
    int cnt0 = 0 , cnt1 = 0 , cnt2 = 0 ;
    Node* temp = head ;
    while(temp != NULL){
        if(temp->data == 0) cnt0++ ; 
        else if(temp->data == 1) cnt1++ ; 
        else cnt2++ ;

        temp = temp->next ; 
    }

    temp = head ;
    while(temp != NULL){
        if(cnt0 > 0){
            temp->data = 0 ;
            cnt0-- ;
        }
        else if(cnt1 > 0){
            temp->data = 1 ;
            cnt1-- ;
        }
        else{
            temp->data = 2 ;
            cnt2-- ;
        }

        temp = temp->next ;
    }

    return head ;
}

// agar interviewer ne bola ki mujhe data replace nahi karna to batao kaise karoge 
// to hum 3 linked list banayenge ek me 0 hoga 2nd me 1 hoga and 3rd me 2 hoga 
// Time complexity O(N) , space complexity O(1)
Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1) ;
    Node* zeroTail = zeroHead ;
    Node* oneHead = new Node(-1) ;
    Node* oneTail = oneHead ;
    Node* twoHead = new Node(-1) ;
    Node* twoTail = twoHead ;

    Node* cur = head ;
    while(cur != NULL){
        if(cur->data == 0){
            zeroTail->next = cur ;
            zeroTail = zeroTail->next ;
        }
        else if(cur->data == 1){
            oneTail->next = cur ;
            oneTail = oneTail->next ;
        }
        else{
            twoTail->next = cur ;
            twoTail = twoTail->next ;
        }
        cur = cur->next ;
    }
    if(zeroHead->next != NULL){
        head = zeroHead->next ;
        if(oneHead->next != NULL){
            zeroTail->next = oneHead->next ;
            oneTail->next = twoHead->next ;
            if(oneTail->next != NULL) twoTail->next = NULL ;
        }
        else{
            zeroTail->next = twoHead->next ;
            if(zeroTail->next != NULL) twoTail->next = NULL ;
        } 
    }
    else if(oneHead->next != NULL){
        head = oneHead->next ;
        oneTail->next = twoHead->next ;
        if(oneTail->next != NULL) twoTail->next = NULL ;
    }
    else head = twoHead->next ;
    return head ;
} 