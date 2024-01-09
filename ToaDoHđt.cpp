#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class ToaDo{
	private:
		float x,y;
	public:
		ToaDo(){
			x=y=0;
		}
		void nhap();
		void xuat();
		float kc(){
			return sqrt(x*x+y*y);
		}
		float kc(ToaDo B){
			ToaDo A=*this;
			return sqrt(pow(A.x-B.x,2) + pow(A.y-B.y,2));
		}
		void setx(float x1){
			x=x1;
		}
		void sety(float y1){
			y=y1;
		}
};

void HCN::nhap(){
	cout << "Nhap hoanh do: "; 
	cin >> x;
	cout << "Nhap tungd do: ";
	cin >> y;	
}
void HCN::xuat(){
	cout << "Hoanh do: " << x << "Tung do: " << y;
}

int main()
{
	ToaDo A,B,O;
	cout << "Nhap diem A \n"; A.nhap();
	cout << "Nhap diem B \n"; B.nhap();
	O.setx(0); O.sety(0);
	cout << "\nAB= "<< A.kc(B);
	cout << "\nOB= " << B.kc();
}

