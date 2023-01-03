// learn this concept form this video link https://www.youtube.com/watch?v=V5-7GzOfADQ
#include <bits/stdc++.h> 
using namespace std ;

/* Time complexity of this algorithm for patter matching is O(n + m) 
    n for traversing the string s and m for building the piTable 
    space complexity of this algorithm is also O(m) for piTable
*/
int main(){
    string s = "ababcabcabababd" ;
    string pattern = "ababd" ;

    int n = s.size() ;
    int m = pattern.size() ;

    vector<pair<char,int>> piTable(m + 1) ;
    for (int i = 1 ; i <= m ; i++)
    {
        piTable[i].first = pattern[i - 1] ;
    }
    
    int j = 1 ;
    
    for (int i = 1 ; i < m ; i++)
    {
        if(s[i] == s[j - 1]){
            piTable[i + 1].second = j ;
            j++ ;
        }
        else{
            j = 1 ;
        }
    }

    int pointer = 0 ;

    for (int i = 0 ; i < n ; i++)
    {
        if(piTable[pointer + 1].first == s[i]){
            pointer++ ;
        }
        else{
            pointer = piTable[pointer + 1].second ;
        }

        if(pointer >= m){
            cout << "found" ;
            return 0 ;
        }
    }

    cout << "Not found" ;
    
    return 0 ;
}