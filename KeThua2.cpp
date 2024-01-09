#include<bits/stdc++.h>

using namespace std;

// Ham tao cua lop con goi gam tao cua lop cha
// Cac ham cua lop con, goi cac ham cua lop cha

class A{
	public:
		A(){
			cout << "Constructor cua lop A\n";
		}
		~A(){
			cout << "Destructor cua lop A\n";
		}
		void xinchao(){
			cout << "Xin chao A! \n";
		}
};
class B{
	public:
		B(){
			cout << "Constructor cua lop B\n";
		}
		~B(){
			cout << "Destructor cua lop B\n";
		}
		void xinchao(){
			cout << "Xin chao B! \n";
		}
};
class C : public A, public B{
	public:
		C(){
			cout << "Constructor cua lop C\n";
		}
		~C(){
			cout << "Destructor cua lop C\n";
		}
		void xinchao(){
			cout << "Xin chao C! \n";
		}
};

int main()
{
	C obj;
	obj.xinchao();
}