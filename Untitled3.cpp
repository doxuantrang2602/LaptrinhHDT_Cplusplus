#include"bits/stdc++.h"
using namespace std;
class xethue{
	string ht,lxe;
	int gio;
	public:
		friend istream&operator>>(istream&,xethue&);
		string getlxe(){
			return lxe;
		}
		friend ostream &operator << (ostream &,xethue &);
		int getgio(){
			return gio;
		}
		string getht(){
			return ht;
		}
};
istream&operator>>(istream &CIN,xethue &xe){
	cout<<"Nhap ten nguoi thue xe : ";CIN.ignore(1);getline(CIN,xe.ht);
	cout<<"Nhap loai xe thue : ";getline(CIN,xe.lxe);
	cout<<"Nhap so gio thue : ";cin>>xe.gio;
	return CIN;
}
ostream &operator << (ostream &Cout, xethue &xe)
{
	Cout <<"Ho Ten: "<<xe.ht<<endl;
	Cout << "So gio: "<< xe.gio<<endl;
	Cout<<"Loai xe: "<<xe.lxe<<endl;
	return Cout;
}
class Ungdung{
	int n;
	xethue *xe;
	public:
		friend istream &operator >>(istream &, Ungdung &);
		friend ostream &operator <<(ostream &, Ungdung &);
		void thanhtien();
};
istream &operator >>(istream &Cin, Ungdung &x)
{
	cout <<"Nhap so nguoi thue xe "; Cin>>x.n;
	x.xe=new xethue[x.n+1];
	
	for(int i=0; i< x.n ;i++)
	{
		cout<<"Nhap thong tin khanh hang thu "<<i+1<<" : \n";
		Cin>>x.xe[i];
	}
	return Cin;
}

void Ungdung::thanhtien()
{
	int gia[n];
	for(int i=0; i<n; i++)
	{
		if(xe[i].getlxe()=="Xe du lich") gia[i]=250+70 *(xe[i].getgio()-1);
		else if(xe[i].getlxe()=="Xe tai") gia[i]=220+85*(xe[i].getgio()-1);
	}
	for(int i=0; i<n; i++)
	{
		cout<<xe[i];
		cout<<"Thanh tien: "<< gia[i]<<" nghin dong"<<endl;
	}
}

int main()
{
	Ungdung xe;
	cin>>xe;
	xe.thanhtien();
 	return 0;
}
