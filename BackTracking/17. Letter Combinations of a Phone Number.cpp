#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void fun(string& digit,vector<string>&ans,int i,int n,vector<string>& store,string& temp,int& total){
        total++ ;
        // cout << 1 << endl ;
        if(i >= n){
            // if(temp.size() > 0)
                ans.push_back(temp) ;
            return ;
        }
        
        int x = digit[i] - '0' ;
        for(int j = 0 ; j < store[x].size() ; j++){
                temp.push_back(store[x][j]) ;
                fun(digit,ans,i+1,n,store,temp,total);
                temp.pop_back() ;
        }
    }
    vector<string> letterCombinations(string digits,int& total) {
        vector<string> store(10) ;
        store[2] = "abc" ;
        store[3] = "def" ;
        store[4] = "ghi" ;
        store[5] = "jkl" ;
        store[6] = "mno" ;
        store[7] = "pqrs" ;
        store[8] = "tuv" ;
        store[9] = "wxyz" ;
        string temp = "" ;
        vector<string> ans ;
        int n = digits.size() ;
        // cout << 1 << endl ;
        
        fun(digits,ans,0,n,store,temp,total) ;
        return ans ;
    }
};

int main(){
    Solution obj ;
    string s ;
    cin >> s ;
    int total = 0 ;
    vector<string> ans = obj.letterCombinations(s,total) ;
    int count = 0 ;
    for(auto &x:ans){
        for(auto &y:x) count++ ;
    }
    cout << total << endl ;
    cout << count << endl ;
    return 0 ;
}