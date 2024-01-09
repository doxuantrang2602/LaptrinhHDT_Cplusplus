#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;

using namespace std;

ll giaS = 40;

class QuanLy{
	string ma,ten,loai;
	int sl;
	
	public:
		void nhap(){
			cout << "Nhap ma: "; fflush(stdin); getline(cin,ma);
			cout << "Nhap ten: "; fflush(stdin); getline(cin,ten);
			cout << "Nhap so luong: "; cin >> sl;
			cout << "Nhap loai: "; fflush(stdin); getline(cin,loai);		
		}
		ll getGia(){
			ll gia;
			if(getLoai() == "S") return gia=giaS;
			else if(getLoai() == "M") return gia = giaS + giaS*0.1;
			else if(getLoai() == "L") return gia = giaS + giaS*0.15;
			return gia;
		}
		string getLoai(){
			return loai;
		}
		int getSoluong(){
			return sl;
		}
		void xuat(){
			cout << " " << ma << " " << ten << " " << sl << " " << loai << " ";
			cout << getGia();
			cout << endl;
		}
};

class UngDung{
	int n;
	QuanLy *ds;
	public:
		void nhap(){
			cout << "Nhap n: "; cin >> n;
			ds = new QuanLy[n];
			for(int i=0;i<n;i++){
				cout << "Don hang thu " << i+1 << endl;
				ds[i].nhap();
			}
		}
		void xuat(){
			for(int i=0;i<n;i++){
				ds[i].xuat();
			}
		}
		void Tinh(){
			ll sS=0, sM=0, sL=0;
			for(int i=0;i<n;i++){
				if(ds[i].getLoai()=="S") sS+= ds[i].getSoluong()*ds[i].getGia();
				if(ds[i].getLoai()=="M") sM+= ds[i].getSoluong()*ds[i].getGia();
				if(ds[i].getLoai()=="L") sL+= ds[i].getSoluong()*ds[i].getGia();
			}
			ll S;
			S= sS + sM + sL;
			cout << "Tong tien thu cac hoa don la " << S << endl;
		}
		
		void Dem(){
			int dem1=0, dem2=0, dem3 =0;
			for(int i=0;i<n;i++){
				if(ds[i].getLoai() == "S") dem1++;
				else if(ds[i].getLoai() == "M") dem2++;
				else if(ds[i].getLoai() == "L") dem3++;
			}
			cout << "Loai S co " << dem1 << endl;
			cout << "Loai M co " << dem2 << endl;
			cout << "Loai L co " << dem3 << endl;
		}
};

int main(){
	UngDung x;
	x.nhap();
	x.xuat();
	x.Tinh();
	x.Dem();
	return 0;
}
