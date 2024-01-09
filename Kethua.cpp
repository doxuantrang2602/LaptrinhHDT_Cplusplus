#include<bits/stdc++.h>

using namespace std;

class Toado{
	float x,y;
	public: 
		Toado(float a=0, float b=0)
		{
			x=a;
			y=b;
		}
		void nhap(){
			cin >> x >> y;
		}	
		void xuat(){
			cout << "Hoanh do: " << x << "Tung do: " << y;
		}
};

class Diem:public Toado{
	int mau;
	public:
		void nhap(){
			Toado::nhap();
			cin >> mau;
		}
		void xuat(){
			Toado::xuat();
			cout << " mau: " << mau;
		}
};
                                                                                                      
int main()
{
	Diem A;  A.nhap(); A.xuat();
	A.Toado::nhap();
	A.Toado::xuat();
}