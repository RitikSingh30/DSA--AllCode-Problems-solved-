#include <bits/stdc++.h> 
using namespace std ;

void merge(stack<int> &s , int x){
    if(s.empty()){
        s.push(x) ;
        return ;
    }

    int u = s.top() ;
    if(u < x){
        s.pop() ;
        merge(s,x) ;
        s.push(u) ;
    }
    else s.push(x) ;
}

void sortSta(stack<int> &s){
    if(s.empty()) return ;

    int peek = s.top() ;
    s.pop() ;
    sortSta(s) ;
    merge(s,peek) ;
}
void sortStack(stack<int> &stack)
{
    sortSta(stack) ;
}

int main(){
	int n ;
	cin >> n ;
	stack<int> s ;
	while(n--){
		int x ;
		cin >> x ;
		s.push(x) ;
	}

	sortStack(s) ;
}