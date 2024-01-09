#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class PhanSo{
	private:
		int x;
		int y;
	public:
		// ham tao khong doi
		PhanSo(){
			
		}	
		// ham tao co doi
		PhanSo(int x, int y){
			this->x=x;
			this->y=y;
		}
		friend PhanSo operator!(PhanSo& p){
			PhanSo c=p;
			c.x=p.x/__gcd(p.x,p.y);
			c.y=p.y/__gcd(p.x,p.y);	
			return c;	
		}
		friend istream& operator >> (istream& in, PhanSo& p){
			cout << "Nhap tu so: "; in >> p.x;
			cout << "Nhap mau so: "; in >> p.y;
			return in;		
		}
		friend ostream& operator << (ostream& out, PhanSo& p){
			p=!p;
			out << p.x << "/" << p.y << " " << endl; 
			return out;
		}
		friend PhanSo operator+(PhanSo& a, PhanSo& b){
			PhanSo c;
			c.x = a.x*b.y + b.x*a.y;
			c.y = a.y*b.y;
			c=!c;
			return c;
		}
		friend PhanSo operator-(PhanSo& a,PhanSo& b){
			PhanSo c;
			c.x = a.x*b.y - b.x*a.y;
			c.y = a.y*b.y;
			c=!c;
			return c;
		}
		friend PhanSo operator^(PhanSo a,PhanSo b){
			PhanSo c;
			c.x = a.x*b.x;
			c.y = a.y*b.y;
			c=!c;
			return c;
		}
		friend PhanSo operator/(PhanSo a, PhanSo b){
			PhanSo c;
			c.x = a.x*b.y;
			c.y = a.y*b.x;
			c=!c;
			return c;
		}
};

int main(){
//	PhanSo p1;
//	cin >> p1;
//	cout << "p1= "<< p1;
//	PhanSo p2;
//	cin >> p2;
//	cout<< "p2= " << p2;
//	PhanSo p3;
//	cin >> p3;
//	cout<< "p3= " << p3;
//	PhanSo p4;
//	cin >> p4;
//	cout<< "p4= " << p4;
//	PhanSo p;
//	p=(p1+p2)*p1/(p3-p4);
//	p=!p;
//	cout << "Bieu thuc (p1+p2)/(p3-p4) * p1 = " << p << endl;
	PhanSo p, p1(1, 2), p2(3, 6), p3(1,1), p4(4, 8);
	cout << "p1 = " << p1 << endl << "p2 = " << p2 << endl << "p3 = " << p3 << endl << "p4 = " << p4 << endl;
	cout << "(p1 + p2) / (p3 - p4) * p1 = ";
	p = (p1 + p2) / (p3 - p4) ^ p1;
	cout << p;
	return 0;
}
