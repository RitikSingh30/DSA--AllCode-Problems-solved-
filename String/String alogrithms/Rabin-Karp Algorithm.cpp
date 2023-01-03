// https://www.geeksforgeeks.org/palindrome-substring-queries/  // check this artical for palindrome query you will learn new thing 
#include <iostream> 
using namespace std ;

void search(string txt , string pattern){
    int n = txt.size() ;
    int m = pattern.size();

    int d = 256 ;
    int mod = 11 ;
    int h = 1 ; // h = pow(d,m - 1) 

    int t = 0 ; // hash value for window 
    int p = 0 ; // hash value for patter 

    // calculating the value of h 
    for (int i = 0 ; i < m - 1 ; i++)
    {
        h = (h * d) % mod ; 
    }

    for (int i = 0 ; i < m ; i++)
    {
        // formula for removing initial window 
        t = (d * t + txt[i]) % mod ;
        p = (d * p + pattern[i]) % mod ; 
    }

    for (int i = 0 ; i <= n - m ; i++)
    {
        if(p == t){

            bool same = true ;
            for (int j = 0 ; j < m ; j++)
            {
                if(txt[i + j] != pattern[j]){
                    same = false ;
                    break ;
                }
            }

            if(same){
                cout << "Pattern found at index : " << i << endl ;
            }
            
        }
        
        if(i < n - m){
            t = (d * (t - txt[i] * h) + txt[i + m]) % mod ;

            // t might become negative 
            if(t < 0) t = t + mod ;
        }
    }
    
}

int main(){
    string txt = "GEEKS FOR GEEKS"; 
    string pattern = "GEEK";

    search(txt,pattern) ;

    return 0 ;
}