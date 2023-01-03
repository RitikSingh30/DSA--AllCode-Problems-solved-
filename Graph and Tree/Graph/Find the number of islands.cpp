  public:
  int dr[] = {0,0,1,-1,-1,1,-1,1} ;
  int dc[] = {1,-1,0,0,-1,-1,1,1} ;
    void no_of_island(vector<vector<char>>& grid , int x , int y , int row , int col){
        if(x<0 || x>=row || y>=col || col<0 || grid[x][y]!='1'){
            return ;
        }
        grid[x][y] = '2' ;
        for (int i = 0 ; i < 8 ; i++)
        {
            no_of_island(grid,x+dr[i],y+dc[i],row,col) ;
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size() ;
        int col = grid[0].size() , count = 0 ;
        for (int i = 0 ; i < row ; i++)
        {
            for (int j = 0 ; j < col ; j++)
            {
                if(grid[i][j]=='1'){
                    no_of_island(grid,i,j,row,col) ;
                    count++ ;
                }
            }
            
        }
        return count ;
    }
};

/* same approach hai upar wale jaise bas upar for loop use kar ke recursive function call kiya hai and yaha pe bina for loop ke 
recursive function call kiya hai*/
  public:
    void no_of_island(vector<vector<char>>& grid , int x , int y , int row , int col){
        if(x<0 || x>=row || y>=col || col<0 || grid[x][y]!='1'){
            return ;
        }
        grid[x][y] = '2' ;
        no_of_island(grid,x+1,y,row,col) ; 
        no_of_island(grid,x,y+1,row,col) ;
        no_of_island(grid,x-1,y,row,col) ;
        no_of_island(grid,x,y-1,row,col) ;
        no_of_island(grid,x-1,y-1,row,col) ;
        no_of_island(grid,x+1,y-1,row,col) ;
        no_of_island(grid,x-1,y+1,row,col) ;
        no_of_island(grid,x+1,y+1,row,col) ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size() ;
        int col = grid[0].size() , count = 0 ;
        for (int i = 0 ; i < row ; i++)
        {
            for (int j = 0 ; j < col ; j++)
            {
                if(grid[i][j]=='1'){
                    no_of_island(grid,i,j,row,col) ;
                    count++ ;
                }
            }
            
        }
        return count ;
        
    }
};

