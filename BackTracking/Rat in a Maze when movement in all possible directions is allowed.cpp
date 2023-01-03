// // // Author : RITIK 

// // GFG solution 
// class Solution{
//     public:
//     string s ;
//     vector<string>v; 
//     bool is_possible(int row , int col , vector<vector<int>>&m , int size,vector<vector<bool>>&visited){
// 	// if(m[row][col]==0 || visited[row][col] || row>=size || col>=size || row < 0 || col < 0){
// 		if( row>=size || col>=size || row < 0 || col < 0 || m[row][col]==0 || visited[row][col]){
// 		return false ;
// 	}
// 	return true ;
//     }
//     void ratInMace(int row ,int col , int size , vector<vector<int>>&m,vector<vector<bool>>&visited){

// 	if(row==size-1 && col==size-1){
// 		v.push_back(s) ;
// 		return ;
// 	}
// 	// upward
// 	if(is_possible(row-1 , col , m , size,visited)){
// 		s.push_back('U') ;
// 		visited[row][col] = 1 ;
// 		ratInMace(row-1 , col , size , m ,visited) ;
// 		s.pop_back() ;
// 		visited[row][col] = 0 ;
// 	}
// 	//downward
// 	if(is_possible(row+1 , col , m , size,visited)){
// 		s.push_back('D') ;
// 		visited[row][col] = 1 ;
// 		ratInMace(row+1 , col , size , m,visited ) ;
// 		s.pop_back() ;
// 		visited[row][col] = 0 ;
// 	}
// 	//left
// 	if(is_possible(row , col-1 , m , size,visited)){
// 		s.push_back('L') ;
// 		visited[row][col] = 1 ;
// 		ratInMace(row , col-1 , size , m ,visited) ;
// 		s.pop_back() ;
// 		visited[row][col] = 0 ;
// 	}
// 	//right
// 	if(is_possible(row , col+1 , m , size,visited)){
// 		s.push_back('R') ;
// 		visited[row][col] = 1 ;
// 		ratInMace(row , col+1 , size , m ,visited) ;
// 		s.pop_back() ;
// 		visited[row][col] = 0 ;
// 	}
// }
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         vector<vector<bool>>visited(n,vector<bool>(n,0)) ;
//         if(m[0][0]) ratInMace(0,0,n,m,visited) ;
//         sort(v.begin(),v.end()) ;
//         return v ;
//     }
// };

// My complier solution (both the solutions are correct)

# include <bits/stdc++.h>
using namespace std;

string s ;

bool is_possible(int row , int col , vector<vector<int>>&m , int size,vector<vector<bool>>&visited){
		if( row>=size || col>=size || row < 0 || col < 0 || m[row][col]==0 || visited[row][col]){
		return false ;
	}
	return true ;
}
void ratInMace(int row ,int col , int size , vector<vector<int>>&m,vector<vector<bool>>&visited){

	if(row==size-1 && col==size-1){
		cout << s << ' ' ;
		return ;
	}
	// upward
	if(is_possible(row-1 , col , m , size,visited)){
		s.push_back('U') ;
		visited[row][col] = 1 ;
		ratInMace(row-1 , col , size , m ,visited) ;
		s.pop_back() ;
		visited[row][col] = 0 ;
	}
	//downward
	if(is_possible(row+1 , col , m , size,visited)){
		s.push_back('D') ;
		visited[row][col] = 1 ;
		ratInMace(row+1 , col , size , m,visited ) ;
		s.pop_back() ;
		visited[row][col] = 0 ;
	}
	//left
	if(is_possible(row , col-1 , m , size,visited)){
		s.push_back('L') ;
		visited[row][col] = 1 ;
		ratInMace(row , col-1 , size , m ,visited) ;
		s.pop_back() ;
		visited[row][col] = 0 ;
	}
	//right
	if(is_possible(row , col+1 , m , size,visited)){
		s.push_back('R') ;
		visited[row][col] = 1 ;
		ratInMace(row , col+1 , size , m ,visited) ;
		s.pop_back() ;
		visited[row][col] = 0 ;
	}
}

int main(){
int n ;
	cin >> n ;
	vector<vector<bool>>visited(n,vector<bool>(n,0)) ;
	vector<vector<int>>m ;
	for (int i = 0 ; i < n ; i++)
	{
		vector<int>vv ;
		for (int j = 0; j < n ; j++)
		{
			int b ;
			cin >> b ;
			vv.push_back(b) ;
		}
		m.push_back(vv) ; 
	}
	if(m[0][0]) ratInMace(0,0,n,m,visited) ;
	else cout << -1 ;
	
	return 0;
}
