#include <iostream>
#include<vector>
using namespace std ;

/* A utility function to print solution */
void print(vector<vector<int>>&v,int n , int m){
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            cout << v[i][j] << ' ' ;
        }
        cout << endl ;
    }

}

/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool can_Place(vector<vector<int>>&v , int row , int col,int size){

    /* Check this row on left side */
    for (int i = 0 ; i <= col ; i++)
        if(v[row][i])
            return false ;
    
     /* Check upper diagonal on left side */
    for (int i = row , j = col ; i >= 0 && j>= 0 ; i-- , j-- )
        if(v[i][j])
            return false ;
    
    /* Check lower diagonal on left side */
    for(int i = row , j = col ; i<size && j>=0 ; i++ , j--)
        if(v[i][j])
            return false ;
    return true ;
    
}

/* A recursive utility function to solve N
   Queen problem */
bool possible(vector<vector<int>>&v , int col , int size){

    /* base case: If all queens are placed
      then return true */
    if(col>=size){
        return true ;
    }

     /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0 ; i < size ; i++)
    {
        /* Check if the queen can be placed on
          board[i][col] */
        if(can_Place(v,i,col,size)){
            /* Place this queen in board[i][col] */
            v[i][col] = 1 ;

            /* recur to place rest of the queens */
            if(possible(v,col+1,size))
                return true ;

            
            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            v[i][col] = 0 ; //Backtracking
        }
    }
      /* If the queen cannot be placed in any row in
        this colum col  then return false */
    return false ;
    
}

/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to 
   solve the problem. It returns false if queens
   cannot be placed, otherwise, return true and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
bool printqueen(vector<vector<int>>&v,int row,int col,int start ,int size){
    if(possible(v,start,size)){
        cout << "YES" << endl ;
        print(v,row,col) ;
        return true ;
    }
    cout << "NO" << endl ;
    return false ;
}


int main(){
    int n ;
    cin >> n ;
    vector<vector<int>>v ;
    for (int i = 0; i < n ; i++)
    {
        vector<int>vv ;
        for (int j = 0; j < n ; j++)
        {
            vv.push_back(0) ;
        }
        v.push_back(vv) ;
        
    }
    printqueen(v,n,n,0,n) ;
    return 0 ;
}