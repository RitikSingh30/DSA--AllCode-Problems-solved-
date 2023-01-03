void insertAtbottom(stack<int>& s, int x){
    if(s.empty()){
        s.push(x) ;
        return ;
    }
    int peek = s.top() ;
    s.pop() ;
    insertAtbottom(s,x) ;
    s.push(peek) ;
}

void reverse(stack<int> &s){
    if(s.empty()){
        return ;
    }

    int peek = s.top() ;
    s.pop() ;
    reverse(s) ;
    insertAtbottom(s,peek) ;
}

void reverseStack(stack<int> &stack) {
    reverse(stack) ;
}