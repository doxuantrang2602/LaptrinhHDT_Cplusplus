#include<bits/stdc++.h>

using namespace std;

class Nguoi{
	string ht;
	int tuoi;
	public:
		void nhap(){
			cout << "Nhap ho ten: "; cin.ignore(1); getline(cin, ht);
			cout << "Nhap tuoi: "; cin >> tuoi;
		}
		void xuat(){
			cout << ht << " | " << tuoi << " | ";
		}
};

class QLNV:public Nguoi{
	int snct;
	float luong;
	public:
		void nhap(){
			Nguoi::nhap();
			cout << "Nhap nam cong tac: "; cin >> snct;
			cout << "Nhap luong: "; cin >> luong;
		}
		void xuat(){
			Nguoi::xuat();
			cout << snct <<" | " << luong << endl;
		}
		float getLuong(){
			return luong;
		}
		int getSnct(){
			return snct;
		}
};

class UngDung{
	int n;
	QLNV *ds;
	public:
		void nhap();
		void xuat();
		void luongtb();
		void snct_max();
};

void UngDung::nhap(){
	cout << "Nhap so nhan vien: "; cin >>n;
	ds = new QLNV[n];
	for(int i=0;i<n;i++){
		cout <<"Thong tin nhan vien thu " << i+1 << endl;
		ds[i].nhap();
	}
}

void UngDung::xuat(){
	for(int i=0;i<n;i++){
		ds[i].xuat();
	}
}
void UngDung::luongtb(){
	float luongtb=0;
	for(int i=0;i<n;i++){
		luongtb+=ds[i].getLuong();
	}
	luongtb = luongtb/n;
	cout << "Luong tb cua nhan vien la: " << luongtb << endl;
	
}

void UngDung::snct_max(){
	int nammax=0;
	for(int i=0;i<n;i++){
		nammax= max(nammax, ds[i].getSnct());
	}
	for(int i=0;i<n;i++){
		if(nammax == ds[i].getSnct()){
			ds[i].xuat();
		}
	}
}
int main(){
	UngDung x;
	x.nhap();
	x.xuat();
	x.luongtb();
	x.snct_max();
	return 0;
}