#include<bits/stdc++.h> 
using namespace std;

set<string> store ;

void fun(string& temp , string& original , int n){

	if(original.size() <= 1){
		temp.push_back(original[0]) ;
		if(temp.size() == n) store.insert(temp) ;
		temp.pop_back() ;
		return ;
	}

	int sz = original.size() ;

	for(int i = 0 ; i < sz ; i++){

		temp.push_back(original[i]) ;

		string s = original ;
		s.erase(i,1) ;

		fun(temp,s,n) ;

		temp.pop_back() ;

	}
}

int main()
{
	string s ;
	cin >> s ;

	string temp ;
	fun(temp,s,s.size()) ;

	cout << store.size() << '\n' ;
	for(auto &x:store){
		cout << x << '\n' ;
	}	
}