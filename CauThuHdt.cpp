#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class Nguoi{
	private:
		string scm,ht;
		long ns;
	public:
		void nhap(){
			cout << "Nhap so chung thu: "; fflush(stdin); getline(cin,scm);
			cout << "Nhap ho ten: "; fflush(stdin); getline(cin,ht);
			cout << "Nhap nam sinh: "; cin >> ns;
		}	
		void xuat(){
			cout << scm << " | " << ht << " | " << ns << " | ";
		}
		long getNamsinh(){
			return ns;
		}
};

class CauThu:public Nguoi{
	private:
		int sbt; // so ban thang
		int sptd; // so phut thi dau
	public:
		void nhap(){
			Nguoi::nhap();
			cout << "Nhap so ban thang: "; cin >> sbt;
			cout << "Nhap so phut thi dau: "; cin >> sptd;
		}	
		void xuat(){
			Nguoi::xuat();
			cout << sbt << " | " << sptd << endl;
		}
		int getSbt(){
			return sbt;
		}
		int getSptd(){
			return sptd;
		}
};

class DanhSach{
	private:
		int n;
		CauThu *ds;
	public:
		friend istream& operator >> (istream& in, DanhSach& d){
			cout << "Nhap n: "; in >> d.n;
			d.ds = new CauThu[d.n];
			for(int i=0;i<d.n;i++){
				cout << "Cau thu thu " << i+1 << endl;
				d.ds[i].nhap();
			}
			return in;
		}	
		friend ostream& operator << (ostream& out, DanhSach& d){
			for(int i=0;i<d.n;i++){
				d.ds[i].xuat();
			}
			return out;
		}
		void Tuoi_Min(){
			cout << endl;
			int min=0;
			for(int i=0;i<n;i++){
				if(ds[i].getNamsinh()>min){
					min = ds[i].getNamsinh();
				}
			}
			cout << "=>Cau thu co tuoi tre nhat la: \n";
			for(int i=0;i<n;i++){
				if(min == ds[i].getNamsinh()){
					ds[i].xuat();
				}
			}
		}
		void Tien_thuong(){
			cout << endl;
			cout << "*Danh sach cau thu duoc thuong 5tr la: \n";
			for(int i=0;i<n;i++){
				if(3<=ds[i].getSbt()<5 || ds[i].getSptd()>=500){	
					ds[i].xuat();	
				}		
			}
			cout << endl;
			cout << "*Danh Sach cau thu duoc thuong 7tr la: \n";
			for(int i=0;i<n;i++){
				if(ds[i].getSbt()>5){	
					ds[i].xuat();	
			}	
		}
	}
};

int main(){
	DanhSach x;
	cin >> x;
	cout << x;
	x.Tuoi_Min();
	x.Tien_thuong();
	return 0;
}
