#include<bits/stdc++.h>
using namespace std;
// class : Lop
// thuoc tinh : attribute
// Phuong thuc : method, behavior
// object : Doi tuong
// constructor: ham khoi tao
// destructor : ham huy
// This pointer
// setter getter
// - Encapsulation : Dong goi
// - Access modifer :
// - Private
// - Public
// - Protected
// SV001=>SV002=>SV003 : Static
// Friend function, friend class

// Operator overloading 
// << >> 
// cout : ostream
// cin : istream 


class SinhVien{
	private:
		string id, ten, ns;
		double gpa;
	public:
		friend istream& operator >> (istream &in, SinhVien& a);
		friend ostream& operator << (ostream &out, SinhVien& a);
	 	friend	bool operator < (SinhVien a, SinhVien b);
};
bool operator < (SinhVien a, SinhVien b){
	return b.gpa < a.gpa;
}

istream& operator >> (istream &in, SinhVien& a){
	cout <<"Nhap id: ";
	in >> a.id;
	cout << "Nhap ten: "; in.ignore();
	getline(in, a.ten);
	
cout << "Nhap ngay sinh: "; in >> a.ns;
	cout << "Nhap diem: "; in >> a.gpa;
	return in;
}

ostream& operator << (ostream &out, SinhVien& a){
	cout << " " << a.id << " " << a.ten << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
	return out;
}

int main()
{
	int n; cin >> n;
	int a[n];
	
}