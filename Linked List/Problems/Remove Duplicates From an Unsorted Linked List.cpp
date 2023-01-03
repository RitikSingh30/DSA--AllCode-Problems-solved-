// time complexity O(N) , space complexity O(N) 
Node *removeDuplicates(Node *head)
{
    int n = 1e5 + 10 ;
    vector<int> visited(n,0) ;
    Node* prev = NULL ;
    Node* cur = head ;
    while(cur != NULL){
        if(visited[cur->data]){
            prev->next = cur->next ;
            cur->next = NULL ;
            cur = prev->next ;
            continue;
        }
        visited[cur->data] = 1 ;
        prev = cur ;
        cur = cur->next ;
    }
    return head ;
}

// ek aur approach hai iss problem ko solve karne ke liye jisme hum map ka use karte hai 