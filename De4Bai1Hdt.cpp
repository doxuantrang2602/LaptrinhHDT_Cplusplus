#include<bits/stdc++.h>

using namespace std;

class MatHang{
	string ma, ten, hsx;
	int tgbh, gia;
	public:
		void nhap(){
			cout << "Nhap ma: "; fflush(stdin); getline(cin, ma);
			cout << "Nhap ten: "; fflush(stdin); getline(cin, ten);
			cout << "Nhap hsx: "; fflush(stdin); getline(cin, hsx);
			cout << "Nhap tgbh: "; cin >> tgbh;
			cout << "Nhap gia: "; cin >> gia;
		}
		void xuat(){
			cout << ma << " | " << ten << " | " << hsx << " | " << tgbh << " | " << gia << " | ";
		}
		int getGia(){
			return gia;
		}
		string getHsx(){
			return hsx;
		}
};

class DienThoai:public MatHang{
	string hdh;
	public:
		void nhap(){
			MatHang::nhap();
			cout << "Nhap hdh: "; fflush(stdin); getline(cin, hdh);
		}
		void xuat(){
			MatHang::xuat();
			cout << hdh << endl;
		}
};

class UngDung{
	int n;
	DienThoai *ds;
	public:
		void nhap(){
			cout << "Nhap so dt: "; cin >> n;
			ds = new DienThoai[n];
			for(int i=0;i<n;i++){
				cout << "Nhap thong tin dien thoai thu " << i+1 << endl;
				ds[i].nhap();
			}
		}
		void xuat(){
			for(int i=0;i<n;i++){
				ds[i].xuat();
			}
		}
		void timx(){
			int x; 
			cout << "Nhap x= "; 
			cin >> x;
			cout << "Danh sach dien thoai co gia khong qua x: " << endl;
			for(int i=0;i<n;i++){
				if(ds[i].getGia() <= x){
					ds[i].xuat();
				}
				else cout << "Khong tim thay dien thoai theo yeu cau !" << endl;
			}
		}
		void timmax(){
			string s;
			cout <<"Nhap hsx can tim: " << endl;
			cin >> s;
			int giamax=0;
			int cnt =0;
			for(int i=0;i<n;i++){
				if(ds[i].getHsx() == "s"){
					cnt ++; 
					if(ds[i].getGia() < giamax){
						giamax = max(giamax, ds[i].getGia());
						
					}
				}
			}
			if(cnt == 0 ){
				cout << "Khong co dien thoai cho hsx vua nhap";
			}
			else{
				for(int i=0;i<n;i++){
					if(giamax == ds[i].getGia()) {
						cout << "Mat hang " << s << "co gia cao nhat la " << giamax <<endl;
					}
			}
		}
	}
};

int main(){
	UngDung x;
	x.nhap();
	x.xuat();
	x.timx();
	x.timmax();
	return 0;
}