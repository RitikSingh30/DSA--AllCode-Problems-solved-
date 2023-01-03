#include <bits/stdc++.h>
using namespace std ;

// https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums
// from here i have learn this concepts 

int main(){
    int n , q; 
    cin >> n >> q ;

    vector<vector<char>> v(n,vector<char>(n)) ;

    for(auto &x:v){
        for(auto &y:x) cin >> y ;
    }

    vector<vector<int>> matrixPrefixSum(n,vector<int>(n,0)) ;

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if(v[i][j] == '*') matrixPrefixSum[i][j] = 1 ;
        }
        
    }

    // Matrix Prefix sum 
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if(i - 1 >= 0) matrixPrefixSum[i][j] += matrixPrefixSum[i - 1][j] ;
            if(j - 1 >= 0) matrixPrefixSum[i][j] += matrixPrefixSum[i][j - 1] ;
            if(i - 1 >= 0 && j - 1 >= 0) matrixPrefixSum[i][j] -= matrixPrefixSum[i - 1][j - 1] ;
        }
    }

    // subRectriangle sum in O(1) 
    while(q--){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        a-- ;
        b-- ;
        c-- ;
        d-- ;

        int ans = matrixPrefixSum[c][d] ;
        if(a - 1 >= 0) ans -= matrixPrefixSum[a - 1][d] ;
        if(b - 1 >= 0) ans -= matrixPrefixSum[c][b - 1] ;
        if(a - 1 >= 0 && b - 1 >= 0) ans += matrixPrefixSum[a - 1][b - 1] ;

        cout << ans << '\n' ;
    }
    
}