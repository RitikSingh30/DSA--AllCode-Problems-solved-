#include <iostream>
using namespace std ;

class a{
public:
	int b ;

	a(int b) : b(b) {}

	// + operator overloading 
	void operator+ (a& obj){
		int value = this->b ;
		int value1 = obj.b ;

		cout << "Operator overloading result is : " << value - value1 << endl ;
	}

	// bracket overloading 
	void operator() (){
		cout << "Mai bracket hu " << endl ;
	}

	// decrement operator overloading 
	void operator-- (){
		b = b - 1 ;
	}

};

int main(){
	a obj(5) , obj1(2) ;

	// jo pehele likhte hai use object ka function call hota hai
	obj1 + obj ;	

	obj() ;

	--obj ;
	cout << obj.b << endl ;

}