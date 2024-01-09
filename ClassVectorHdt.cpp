#include <bits/stdc++.h>
#include <vector>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class Tivi{
	private:
		int ma;
		string hsx,ten;
		double dongia;
		int sl;
	public:
		friend istream& operator >> (istream& in,Tivi& t){
			cout << "Nhap ma: "; in >> t.ma;
			cout << "Nhap hsx: "; in >> t.hsx;
			cout << "Nhap ten Tivi: "; in >> t.ten;
			cout << "Nhap don gia: "; in>> t.dongia;
			cout << "Nhap so luong: "; in >> t.sl;
			return in;
		}
		friend ostream& operator << (ostream& out,Tivi& t){
			out<< "| " <<t.ma<<" | " << t.hsx<< " | " << t.ten << " | " << t.dongia << " | " << t.sl << " |" << endl;
			return out;
		}	
		int getMa(){
			return ma;
		}
		string getHsx(){
			return hsx;
		}
		double getGia(){
			return dongia*sl;
		}
};

class QuanLy{
	private:
		int n;
		vector<Tivi> v;
	public:
		friend istream& operator >> (istream& , QuanLy& );
		friend ostream& operator << (ostream& out,QuanLy& t);
		void Xoa_theo_ma();
		void TinhTong();
		void Search();
};

istream& operator >> (istream& in, QuanLy& t){
	cout << "Nhap so Tivi: "; in >> t.n;
	Tivi a;
	for(int i=0;i<t.n;i++){
		cout << "Nhap thong tin Tivi thu " << i+1 << endl;
		in >> a;
		t.v.push_back(a);
	}	
	return in;
}
ostream& operator << (ostream& out,QuanLy& t){
	cout << "Danh sach thong tin Tivi: \n";
	cout << "*********************************** \n";
	for(int i=0;i<t.v.size();i++){
		out << t.v[i];
	}
	cout << "*********************************** \n";
	return out;
}
void QuanLy::Xoa_theo_ma(){
	int ma_nhap;
	cout << "Nhap ma Tivi can xoa: "; cin >> ma_nhap;
	for(int i=0;i<n;i++){
		if(ma_nhap == v[i].getMa()){
			v.erase(v.begin()+i);
		}
	}
	cout << "Danh sach thong tin Tivi: \n";
	for(int i=0;i<v.size();i++){
		cout << v[i];
	}
}
void QuanLy::TinhTong(){
	int S=0;
	string nhap_hsx;
	cout << "Nhap Hsx can tinh tong: ";
	fflush(stdin); getline(cin,nhap_hsx);
	for(int i=0;i<v.size();i++){
		if(nhap_hsx==v[i].getHsx()){
			S+= v[i].getGia();
		}
	}
	cout << "HSX " << nhap_hsx << " co tong gia tri la " << S << endl; 
}
void QuanLy::Search(){
	int k=0;
	int ma_tim;
	cout << "Nhap ma Tivi can tim: "; cin >> ma_tim;
	int l=0;
	int r=v.size()-1;
	while(l<=r){	
		int m =(l+r)/2;
		if(v[m].getMa() == ma_tim){
			k++;
			cout << "Found !\n";
			cout << v[m];
			break;
		}
		else if(v[m].getMa() > ma_tim){
			r = m-1;
		}
		else{
			l = m+1;
		}
	}
	if(k==0) cout <<"Khong co Tivi can tim !\n";
}

int main(){
	QuanLy x;
	cin >> x;
	cout << x;
	x.Xoa_theo_ma();
	x.TinhTong();
	x.Search();
	return 0;
}
