#include <iostream>
using namespace std ;

class ritik ;
class student ;

// agar suppose humare pass 2 classes hai ritik and student and ritik class me ek function hai print naam se agar ab hum cahte hai ki 
// wo print function class student ka friend ho to hum bana sakte hai but ek chiz ka yaha pe dhayan rakhna padega ki jab print function
// class student ka friend bana tab jis class me print function hai wo class student class ke upar define honi cahiye because compiler
// jab program check karta hai to usko class ritik ke defination class student ke pehele janni hoti hai uske baad hi wo class student me
// ritik class ke function ko friend banayega warna error dega and jo function friend bana hai uss function ka defination class ke andar
// nahi hona cahiye class ke bahar hona cahiye wo bhi student class ke baad 
class ritik{
	public:
		void print(student&);
};

class student{
	int a ; 
	friend class employee ;
	friend void ritik::print(student&) ;
};

void ritik::print(student& obj){
	cout << obj.a << endl ;
}

class employee{
	public:
		void fun(student& obj){
			cout << obj.a << endl ;
		}
		friend class student ;
};

int main(){
	employee obj ;
	student obj1 ;

	obj.fun(obj1) ;

	ritik obj2 ;
	obj2.print(obj1) ;

	return 0 ;
}