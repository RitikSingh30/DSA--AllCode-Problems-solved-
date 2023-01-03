#include <bits/stdc++.h>
using namespace std ;

// https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums
// from here i have learn this concepts 

int main(){
    int n , m ; 
    cin >> n >> m ;

    vector<vector<int>> v(n,vector<int>(m)) ;

    for(auto &x:v){
        for(auto &y:x) cin >> y ;
    }

    vector<vector<int>> matrixPrefixSum(n,vector<int>(m,0)) ;

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            if(i - 1 >= 0) matrixPrefixSum[i][j] += matrixPrefixSum[i - 1][j] ;
            if(j - 1 >= 0) matrixPrefixSum[i][j] += matrixPrefixSum[i][j - 1] ;
            if(i - 1 >= 0 && j - 1 >= 0) matrixPrefixSum[i][j] -= matrixPrefixSum[i - 1][j - 1] ;
            matrixPrefixSum[i][j] += v[i][j] ;
        }
    }

    for(auto &x:matrixPrefixSum){
        for(auto &y:x) cout << y << ' ' ;
        cout << '\n' ;
    }
    
}