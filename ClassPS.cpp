#include<bits/stdc++.h>

using namespace std;

int UCLN(int a, int b)
{
	if(a==0 || b==0)
		return a+b;
	while(a!=b){
		if(a>b){
			a-=b;
		}
		else b-=a;
	}
	return a;
}

typedef struct{
	int ts;
	int ms;
}PS;

PS operator!(const PS &c)
{
	PS x;
	x.ts=c.ts/UCLN(c.ts,c.ms);
	x.ms=c.ms/UCLN(c.ts,c.ms);
	return x;
}
PS operator+(const PS &c1, const PS &c2)
{
	PS c;
	c.ts = (c1.ts*c2.ms) + (c2.ts*c1.ms);
	c.ms = c1.ms*c2.ms;
	c= !c;
	return c;
}

istream &operator >> (istream &x , PS &c)
{
	x>>c.ts;
	while(c.ms!=0){
		x>>c.ms;
	}
	return x;
}
ostream &operator << (ostream &x, const PS& c)
{
	x << c.ts << "/" << c.ms;
}

int main()
{
	PS p1,p2;
	PS p= p1+p2;
	cout << "Nhap tu va mau phan so thu nhat: ";
	cin >> p1.ts >> p1.ms;
	cout << "Nhap tu va mau phan so thu hai: ";
	cin >> p2.ts >> p2.ms;
	cout << "Hai phan so vua nhap la: " << endl; 
	cout << p1 << " " << p2 << endl;
	cout << "Tong: " << p1 << " + " << p2 << " = " << p << endl;
}