#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> cal(string& expression,int start , int end,int n){
        vector<int> temp ;
        if(end - start <= 1){
            if(end - start == 0) temp.push_back(expression[start] - '0') ;
            else{
                int x = expression[start] - '0' ;
                int y = expression[end] - '0' ;
                temp.push_back(x * 10 + y) ;
            }
            return temp ; 
        }
        if(start > end) return temp ;


        for (int i = start ; i <= end ; i++)
        {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> ans = cal(expression,start,i - 1,n) ;
                vector<int> ans1 = cal(expression,i + 1,end,n) ;

                for (int l = 0 ; l < ans.size() ; l++)
                {
                    for (int k = 0 ; k < ans1.size() ; k++)
                    {
                        if(expression[i] == '+'){
                            temp.push_back(ans[l] + ans1[k]) ;
                        }
                        else if(expression[i] == '-'){
                            temp.push_back(ans[l] - ans1[k]) ;
                        }
                        else{
                            temp.push_back(ans[l] * ans1[k]) ;
                        }
                    }
                }
            }
        }

        return temp ;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size() ;
        vector<int> ans = cal(expression,0,n-1,n) ;
        return ans ;
    }
};

int main(){
    string s ;
    cin >> s ;
    Solution obj ;
    vector<int> ans = obj.diffWaysToCompute(s) ;
    for(auto &x:ans) cout << x << ' ' ;
    return 0 ;
}
