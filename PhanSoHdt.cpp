#include<bits/stdc++.h>

using namespace std;

class PhanSo{
	private:
		int x;
		int y;	
	public:
		PhanSo(){
			x=0;
			y=0;
		}
		PhanSo(int x, int y){
			this->x=x;
			this->y=y;
		}
		friend istream& operator >> (istream& ,PhanSo& );
		friend ostream& operator << (ostream& ,PhanSo& ); 	
		friend PhanSo operator ! (PhanSo c);
		friend PhanSo operator+(PhanSo &c1, PhanSo &c2);
		friend PhanSo operator-(PhanSo &c1, PhanSo &c2);
		friend PhanSo operator/(const PhanSo &c1,const PhanSo &c2);
		friend PhanSo operator*(const PhanSo &c1,const PhanSo &c2);
};
PhanSo operator ! (PhanSo c){
	PhanSo b;
	b.x = c.x/__gcd(c.x,c.y);
	b.y = c.y/__gcd(c.x,c.y);
	return b;
}
istream& operator >> (istream& in,PhanSo& ps){
	cout << "Nhap phan so: "; in>> ps.x >> ps.y;
	return in;
}
ostream& operator << (ostream& out,PhanSo& ps){
	out << ps.x << "/" << ps.y << endl;
	return out;
}
PhanSo operator+(PhanSo &c1, PhanSo &c2){
	PhanSo c;
	c.x = c1.x*c2.y + c2.x*c2.y;
	c.y = c1.y*c2.y;
	c=!c;
	return c;
}
PhanSo operator-(PhanSo &c1, PhanSo &c2){
	PhanSo c;
	c.x = c1.x*c2.y - c2.x*c2.y;
	c.y = c1.y*c2.y;
	c=!c;
	return c;
}
PhanSo operator*(const PhanSo &c1,const PhanSo &c2){
	PhanSo c;
	c.x = c1.x*c2.x;
	c.y = c1.y*c2.y;
	c=!c;
	return c;
}
PhanSo operator/(const PhanSo &c1,const PhanSo &c2){
	PhanSo c;
	c.x = c1.x*c2.y;
	c.y = c1.y*c2.x;
	c=!c;
	return c;
}


int main()
{
	PhanSo x1;
	cin >> x1;
	cout << x1;
	PhanSo x2;
	cin >> x2;
	cout << x2;
	PhanSo x3;
	cin >> x3;
	cout << x3;
	PhanSo x4;
	cin >> x4;
	cout << x4;
	PhanSo s = (x1+x2)/(x3-x4)*x1;
	cout << s;
	return 0;
}