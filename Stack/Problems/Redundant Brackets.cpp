#include <bits/stdc++.h> 
using namespace std ;

bool opera(char c){
    if(c == '+' or c == '-' or c == '*' or c == '/') return 1 ;
    return 0 ;
}

bool findRedundantBrackets(string &s)
{
    stack<char> ss ;
    int n = s.size() ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '(' or opera(s[i])) ss.push(s[i]) ;
        else{
            if(s[i] == ')'){
                bool fang = 0 ;
                while(!ss.empty()){
                    if(ss.top() != '(') fang = 1 ;
                    else if(ss.top() == '('){
                        ss.pop() ;
                        break ;
                    }
                    ss.pop() ;
                }
                if(!fang) return 1 ;
            }
        }
    }

    return 0 ;
}


int main(){
    int t ;
    cin >> t ;
    while(t--){
        string s ;
        cin >> s ;
        cout << findRedundantBrackets(s) << endl ;    
    }
}