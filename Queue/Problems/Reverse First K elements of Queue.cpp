// TC = O(max(k,n-k)) , SC = O(K) 
queue<int> modifyQueue(queue<int> q, int k) {
    int n = q.size() ;
    stack<int> s ;
    for(int i = 0 ; i < k ; i++){
        s.push(q.front()) ;
        q.pop() ;
    }
    while(!s.empty()){
        q.push(s.top()) ;
        s.pop() ;
    }
    
    for(int i = 0 ; i < (n - k) ; i++){
        int x = q.front() ;
        q.pop() ;
        q.push(x) ;
    }
    
    return q ;
}