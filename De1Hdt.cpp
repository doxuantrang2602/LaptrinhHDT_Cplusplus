#include<bits/stdc++.h>

using namespace std;

class PS{
	private:
		int tuso;
		int mauso;
	public:
		PS(){
			tuso = 0;
			mauso = 0;
		}	
		PS(int tuso, int mauso){
			this->tuso = tuso;
			this->mauso = mauso;
		}
		friend PS operator!(PS c);
		void nhap();
		friend ostream &operator << (ostream &out, PS &);
		friend PS operator*(const PS &c1, const PS &c2);
};

PS operator!(PS c){
	PS b;
	b.tuso = c.tuso/__gcd(c.tuso, c.mauso);
	b.mauso = c.mauso/__gcd(c.tuso, c.mauso);
	return b;
}

void PS::nhap(){
	cout << "Nhap tu so: "; cin >> tuso;
	cout << "Nhap mau so: "; cin >> mauso;
}

ostream &operator << (ostream &out, PS &c){
	out << c.tuso << "/" << c.mauso << endl;
	return out;
}

PS operator*(const PS &c1, const PS &c2){
	PS c;
	c.tuso = c1.tuso*c2.tuso;
	c.mauso = c1.mauso*c2.mauso;
	c =!c;
	return c;
}

int main(){
	PS p1;
	p1.nhap();
	p1 =!p1;
	cout << p1;
	PS p2;
	p2.nhap();
	p2 =!p2;
	cout << p2;
	PS p = p1*p2;
	p =!p;
	cout << p << endl;
	return 0;
}