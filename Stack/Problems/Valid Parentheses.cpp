bool isValidParenthesis(string expression)
{
    stack<char> s ;
    int n = expression.size() ;
    for(int i = 0 ; i < n ; i++){
         if(expression[i] == ')'){
             if(s.empty() or s.top() != '(') return false ;
             else s.pop() ;
         }
         else if(expression[i] == ']'){
             if(s.empty() or s.top() != '[') return false ;
             else s.pop() ;
         }
         else if(expression[i] == '}'){
             if(s.empty() or s.top() != '{') return false ;
             else s.pop() ;
         }
         else s.push(expression[i]) ;
    }

    return s.empty() ;
}