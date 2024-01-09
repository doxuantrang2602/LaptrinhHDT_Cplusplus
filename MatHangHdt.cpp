#include<bits/stdc++.h>

using namespace std;

class MatHang{
	string ma, ten, nsx;
	int sl, gia;
	public:
		string getTen(){
			return ten;
		}
		int getGia(){
			return gia;
		}
		int getSl(){
			return sl;
		}
		void nhap();
		void xuat();
};

void MatHang::nhap(){
	cout << "Nhap ma: "; cin.ignore(1); getline(cin, ma);
	cout << "Nhap ten: "; getline(cin, ma);
	cout << "Nhap nsx: "; getline(cin, nsx);
	cout << "Nhap so luong: "; cin >> sl;
	cout << "Nhap don gia: "; cin >> gia;
}

void MatHang::xuat(){
	cout << ma << " | " << ten << " | " << nsx << " | " << sl << " | " << gia << " | ";
}

class MayTinh:public MatHang{
	string loaiCPU, hdh; 
	int tronglg;
	public:
		string getHdh(){
			return hdh;
		}
		void nhap();
		void xuat();
};

void MayTinh::nhap(){
	MatHang::nhap();
	cout << "Nhap loai CPU: "; fflush(stdin); getline(cin, loaiCPU);
	cout << "Nhap hdh (Windows, Linux, Max): "; fflush(stdin); getline(cin, hdh);
	cout << "Nhap trong luong: "; cin >> tronglg;
}

void MayTinh::xuat(){
	MatHang::xuat();
	cout << loaiCPU << " | " << hdh << " | " << tronglg << endl;
}

class UngDung{
	int n;
	MayTinh *ds;
	public:
		void nhap();
		void xuat();
		void hethang();
		void window_max();
};

void UngDung::nhap(){
	cout << "Nhap so may tinh: "; cin >> n;
	ds = new MayTinh[n];
	for(int i=0; i<n;i++){
		cout << "Nhap may tinh thu " << i+1 << endl;
		ds[i].nhap();
	}
}

void UngDung::xuat(){
	for(int i=0;i<n;i++){
		ds[i].xuat();
	}
}
void UngDung::hethang(){
	cout << "Danh sach mat hang het hang: " << endl;
	for(int i=0;i<n;i++){
		if(ds[i].getSl() == 0){
			ds[i].getTen(); cout << endl;
		}
	}
}
void UngDung::window_max(){
	int giamax=0;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(ds[i].getHdh() == "Windows"){
			giamax = max(giamax, ds[i].getGia());
			cnt ++;
		}
	}
	if(cnt == 0) cout << "Khong co mat hang nao co hdh Windows " << endl;
	else{
		cout << "Mat hang co don gia cao nhat la: " << endl;
		for(int i=0; i<n;i++){
			if(ds[i].getGia() == giamax){
				ds[i].getTen();
			}
		}
	}
}
int main(){
	UngDung x;
	x.nhap();
	x.xuat();
	x.hethang();
	x.window_max();
	return 0;
}