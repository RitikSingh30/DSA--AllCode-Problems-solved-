#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 10 ;

int vis[8][8] ; // to keep the track of visited or not 
int level[8][8] ; // to keep the track of levels 

int getX(string s){    // change the x co-ordinate into int 
    return s[0] - 'a' ;  
}
int getY(string s){   // change the Y co-ordinate into int 
    return s[1] - '1' ;
}

bool isValid(int x , int y){   // to check whether the knight can go in that grid
    return x>=0 && y>=0 && x<8 && y<8 ;
}

vector<pair<int,int>> movements {      // all the 8 movements of the knight 
    {-1,2},{1,2},{-1,-2},{1,-2},{2,-1},{2,1},{-2,-1},{-2,1}
};

int bfs(string source , string dest){
    int sourceX = getX(source) ; // access the x co-ordinate of the source 
    int sourceY = getY(source) ; // access the y co-ordinate of the source 
    int destX = getX(dest) ;  // access the x co-ordinate of the destination
    int destY = getY(dest) ;  // access the y co-ordinate of the destination  
    queue<pair<int,int>> q ;  // queue ko pair me banaya because hume usme x and y co-ordinate store karna tha
    q.push({sourceX,sourceY}) ; // pushing stating co-ordinate
    vis[sourceX][sourceY] = 1 ;
    level[sourceX][sourceY] = 0 ;
    while(!q.empty()){
        pair<int,int> v = q.front() ;
        int x = v.first , y = v.second ;
        q.pop() ;
        for(auto movement : movements){
            int childX = movement.first + x ;
            int childY = movement.second + y ;
            if(!isValid(childX,childY)) continue ;
            if(!vis[childX][childY]){
                q.push({childX,childY}) ;
                level[childX][childY] = level[x][y] + 1 ;
                vis[childX][childY] = 1 ;
            }
        }
        if(level[destX][destY] != inf){
            break ;
        }
    }
    return level[destX][destY] ;
}

void reset(){
    for (int i = 0; i < 8 ; i++)
    {
        for (int j = 0 ; j < 8 ; j++)
        {
            level[i][j] = inf ;
            vis[i][j] = 0 ;
        }
    }
}

int main(){
    int t ;
    cin >> t ;
    while(t--){
        reset() ;
        string s1 , s2 ;
        cin >> s1 >> s2 ;
        cout << bfs(s1,s2) << endl ;

    } 
    return 0;
}