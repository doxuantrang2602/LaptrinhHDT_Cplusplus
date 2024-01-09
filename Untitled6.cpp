#include<bits/stdc++.h>

using namespace std;

class phanso{
	int tuso,mauso;
	public:
		phanso(){
			tuso=2; mauso=5;
		}
		phanso(const int& ts, const int& ms){
			tuso = ts; mauso = ms;
		}
		friend ostream& operator <<(ostream&, phanso&);
		friend istream& operator >>(istream&, phanso&);
		phanso rutgon(phanso&);	
		friend phanso operator+(const phanso&, const phanso&);
		friend phanso operator-(const phanso&, const phanso&);
		friend phanso operator*(const phanso&, const phanso&);
		friend phanso operator/(const phanso&, const phanso&);	
};

phanso phanso::rutgon(phanso& c){
				phanso x=c;
				x.tuso = c.tuso/__gcd(c.tuso,c.mauso);
				x.mauso = c.mauso/__gcd(c.tuso,c.mauso);
				return x;
		}
phanso operator+(const phanso& p1, const phanso& p2){
	phanso x;
	x.tuso = p1.tuso*p2.mauso + p2.tuso*p1.mauso;
	x.mauso = p1.mauso*p2.mauso;
	return x;
}

phanso operator-(const phanso& p1, const phanso& p2){
	phanso x;
	x.tuso = p1.tuso*p2.mauso - p2.tuso*p1.mauso;
	x.mauso = p1.mauso*p2.mauso;
	return x;
}

phanso operator*(const phanso& p1, const phanso& p2){
	phanso x;
	x.tuso = p1.tuso*p2.tuso;
	x.mauso = p1.mauso*p2.mauso;
	return x;
}

phanso operator/(const phanso& p1, const phanso& p2){
	phanso x;
	x.tuso = p1.tuso*p2.mauso;
	x.mauso = p1.mauso*p2.tuso;
	return x;
}

istream& operator >>(istream& in, phanso& ps){
	cout << "Nhap tu so : "; in >> ps.tuso;
	do{
		cout << "Nhap mau so : "; in >> ps.mauso;
	}while(ps.mauso == 0);
	return in;
}
ostream& operator <<(ostream& out, phanso& ps){
	out << ps.tuso << "/" << ps.mauso;
	return out;
}
int main(){
  	phanso p1,p2,p3,p4;
  	cin >> p1;
  	cout << "phan so vua nhap la: " << p1 << endl;
  	p1 = p1.rutgon(p1);
  	cout << "phan so sau khi rut gon: " << p1 << endl;
  	
  	cin >> p2;
  	cout << "phan so vua nhap la: " << p2 << endl;
  	p2 = p2.rutgon(p2);
  	cout << "phan so sau khi rut gon: " << p2 << endl;
  	
  	cin >> p3;
  	cout << "phan so vua nhap la: " << p3 << endl;
  	p3 = p3.rutgon(p3);
  	cout << "phan so sau khi rut gon: " << p3 << endl;
  	
  	cin >> p4;
  	cout << "phan so vua nhap la: " << p4 << endl;
  	p4 = p4.rutgon(p4);
  	cout << "phan so sau khi rut gon: " << p4 << endl;
  	
  	phanso bt = (p1+p2)/(p3-p4)*p1;
  	bt = bt.rutgon(bt);
  	cout << "Gia tri bieu thuc: " << bt << endl;
}
