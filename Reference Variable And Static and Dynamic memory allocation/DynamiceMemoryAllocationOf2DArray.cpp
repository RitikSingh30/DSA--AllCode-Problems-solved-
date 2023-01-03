#include <iostream>
using namespace std ;

int main(){
    int n , m ;
    cin >> n >> m ;

    // Creating row of 2D array dynamically 
    int** arr = new int*[n] ;
    
    // Creating column of 2D array dynamically 
    for(int i = 0 ; i < n ; i++){
        arr[i] = new int[m] ;
    }

    // Taking input in 2D array 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j] ;
        }
    }

    // output the 2D array 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j] << ' ' ;
        }
        cout << endl ;
    }

    // Relising the column of 2D dnyamic array 
    for(int i = 0 ; i < n ; i++){
        delete []arr[i] ;
    }

    // REalising the row of 2D dynamic array 
    delete []arr ;

    return 0 ;
}
