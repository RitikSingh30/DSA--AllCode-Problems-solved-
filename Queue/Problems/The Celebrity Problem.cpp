// TC = O(N^2) , SC = O(1) 
int celebrity(vector<vector<int> >& M, int n) 
{
    int ind = -1 , cnt = 0 ;   
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = 0 ; j < n ; j++){
            if(M[i][j] == 1) break ;
            else if(j == n - 1){
                cnt++ ;
                ind = i ;
            }
        }
    } 

    return (cnt >= 2 or cnt <= 0 ? -1 : ind) ;
}

// two pointer approach read from the editorial TC = O(N) , SC = O(1)  
int celebrity(vector<vector<int> >& M, int n) 
{  
    int i = 0 , j = n - 1 ;
    while(i < j){
        if(M[i][j] == 1) i++ ;
        else j-- ;
    }

    bool row = true , col = true ;
    for(int i = 0 ; i < n ; i++){
        if(M[j][i] == 1) row = false ;
    }

    for(int i = 0 ; i < n ; i++){
        if(M[i][j] == 0 and i != j) col = false ;
    }

    return (row == 1 and col == 1 ? j : -1) ;

}