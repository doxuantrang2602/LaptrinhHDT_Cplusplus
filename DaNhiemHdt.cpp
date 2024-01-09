#include<bits/stdc++.h>
using namespace std;


class A{
	public:
		virtual void f(); // phuong thuc thuan ao
		
	//	virtual void f()		// ham ao
	//	{
	//		cout << "Chuc nang A";
	//	}
}; 

class B:public A{
	public:
		virtual void f()
		{
			cout << "\nChuc nang B";
		}
};

class C:public B{
	public:
		virtual void f()
		{
			cout << "\nChuc nang C";
		}
};

void DaNhiem(A *p)
{
	p->f();
}
int main ()
{
	A a;
	B b;
	C c;
	DaNhiem(&a);
	DaNhiem(&b);
	DaNhiem(&c);
	
}
