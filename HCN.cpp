#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class HCN{
	private:
		float cd, cr;
	public:
		void nhap();
		void xuat();
		float tinhdt(){
			return cd*cr;
		}
};

void HCN::nhap(){
	cout << "Nhap chieu dai: "; 
	cin >> cd;
	cout << "Nhap chieu rong: ";
	cin >> cr;	
}
void HCN::xuat(){
	cout << "Chieu dai: " << cd << " Chieu rong: " << cr;
}

int main()
{
	HCN h1, h2; 
	h1.nhap();
	float s1=h1.tinhdt();
	h2=new HCN;
	h2->nhap(); // (*h2).nhap;
	float s2=h2->tinhdt();
	cout << "dt h1+h2= " << h1.tinhdt() + h2->tinhdt();
	if(s1>s2){
		cout << "hinh ";h1.xuat();cout << "Co dien tich lon hon";
	}
	else if(s1<s2){
		cout << "hinh ";h2.xuat();cout << "Co dien tich lon hon";
	}
	else cout << "Dien tich hai hinh nhu nhau va bang "<< s1;
	delete(h2);
}

