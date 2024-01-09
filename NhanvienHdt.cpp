#include<bits/stdc++.h>

using namespace std;

class Quanly;

typedef struct{
	int day;
	int month;
	int year;
}date,dateki; 

class Nhanvien{
	private:
		int mnv;
		string ht;
		string gt;
		date ns;
		string address;
		double thue;
		dateki ki;
	public:
		friend class Quanly;
		friend istream& operator >> (istream& , Nhanvien& );
		friend ostream& operator << (ostream& , Nhanvien& );
};

istream& operator >> (istream& in, Nhanvien& nv){
	cout << "Nhap ho ten: "; fflush(stdin); getline(in,nv.ht);
	cout << "Nhap gioi tinh: "; fflush(stdin); getline(in, nv.ht);
	string s;
	cout << "Nhap ngay sinh: "; in >> nv.ns.day; in >> nv.ns.month; in >> nv.ns.year;
	cout << "Nhap address: "; fflush(stdin); getline(in, nv.address);
	cout << "Nhap ma so thue: "; in >> nv.thue;
	cout << "Nhap ngay ki hop dong"; in >> nv.ki.day; in >> nv.ki.month; in >> nv.ki.year;
	return in;
}

ostream& operator << (ostream& out, Nhanvien& nv){
	cout<<" "<<nv.ht<<" "<< nv.gt << nv.ns.day<< "/" <<nv.ns.month << "/" << nv.ns.year<< " " << nv.address<<" " << nv.thue << nv.ki.day << "/"<<nv.ki.month<<"/"<<nv.ki.year<< endl;
	return out;
}

class Quanly{
	int n; 
	Nhanvien *ds;
	public:
		friend istream& operator >> (istream& , Quanly& );
		friend ostream& operator << (ostream& , Quanly& );
		void sapxep();
};

istream& operator >> (istream& in, Quanly& nv){
	cout << "Nhap so nhan vien: "; in >> nv.n;
	nv.ds = new Nhanvien[nv.n];
	for(int i=0; i<nv.n; i++){
		cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
		in >> nv.ds[i];
	}
	return in;
}

ostream& operator << (ostream& out, Quanly& nv){
	for(int i=0;i<nv.n;i++){
		out << "0000" << i+1;
		out << nv.ds[i];
	}
	return out;
}

void Quanly::sapxep(){
	for(int i=0;i<0;i++){
		for(int j=i+1;j<n;j++){
			if(ds[i].)
		}
	}
}

int main(){
	Quanly x;
	cin >> x;
	cout << x;
}