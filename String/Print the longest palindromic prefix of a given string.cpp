#include <bits/stdc++.h>
using namespace std ;

int main(){
    string s ;
    cin >> s ;

    int n = s.size() ;

    vector<int> piTable(n) ;

    // creating a pi table 
    for (int i = 1 ; i < n ; i++)
    {
        int j = piTable[i - 1] ;
        while(j > 0 && s[i] != s[j]){
            j = piTable[j - 1] ;
        } 
        if(s[i] == s[j]) j++ ;
        piTable[i] = j ;
    }
    

    // this is the second problem 
    // Create temporary string
    string temp = str + '?';
 
    // Reverse the string str
    reverse(str.begin(), str.end());
 
    // Append string str to temp
    temp += str;
 
    // Find the length of string temp
    int n = temp.length();
 
    // lps[] array for string temp
    int lps[n];
 
    // Initialise every value with zero
    fill(lps, lps + n, 0);
 
    // Iterate the string temp
    for (int i = 1; i < n; i++) {
 
        // Length of longest prefix
        // till less than i
        int len = lps[i - 1];
 
        // Calculate length for i+1
        while (len > 0 && temp[len] != temp[i]) {
            len = lps[len - 1];
        }
 
        // If character at current index
        // len are same then increment
        // length by 1
        if (temp[i] == temp[len]) {
            len++;
        }
 
        // Update the length at current
        // index to len
        lps[i] = len;
    }
 
    // Print the palindromic string of
    // max_len
    cout << temp.substr(0, lps[n - 1]);
    
    
}