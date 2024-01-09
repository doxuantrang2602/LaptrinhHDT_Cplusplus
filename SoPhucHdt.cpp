#include<bits/stdc++.h>


// Nhap vao 2 so phuc roi tinh tong 
// Input: c1, c2
// Output: c1+c2

using namespace std;

class SoPhuc{
	private:
		int thuc;
		int ao;
	public:
		friend istream& operator >>(istream &x, SoPhuc &c);
		friend ostream& operator <<(ostream &x, SoPhuc &c);
		friend SoPhuc operator + (SoPhuc &c1, SoPhuc &c2);
};
istream& operator >> (istream &x, SoPhuc &c){
	x >> c.thuc >> c.ao;
	return x;
}
ostream& operator << (ostream &x, SoPhuc &c){
	x << c.thuc << " " << c.ao;
	return x;
}

SoPhuc operator +(SoPhuc &c1, SoPhuc &c2){
	SoPhuc tong;
	tong.thuc = c1.thuc + c2.thuc;
	tong.ao = c1.ao + c2.ao; 
	return tong;
}
int main()
{
	SoPhuc a, b; cin >>a >> b;
	SoPhuc Tong = a + b;
	cout << Tong << endl;
	return 0;
}