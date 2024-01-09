#include<bits/stdc++.h>

using namespace std;

class NS{
	private:
		string ht;
		int tuoi;
	public:
		void nhap(){
			cout << "Nhap ho ten: "; fflush(stdin); getline(cin, ht);
			cout << "Nhap tuoi: "; cin >> tuoi;
		}
		
		void xuat(){
			cout << ht << " | " << tuoi << " | ";
		}
		string getHoten(){
			return ht;
		}
		int getTuoi(){
			return tuoi;
		}
};

class QL: public NS{
	private:
		string chucvu;
		long luong;
	public:
		void nhap(){
			NS::nhap();
			cout << "Nhap chuc vu: "; fflush(stdin); getline(cin, chucvu);
			cout << "Nhap luong: "; cin >> luong;
		}
		long getTienluong(){
			if(chucvu=="GD") return luong + 15000000;
			else if(chucvu=="TP") return luong + 10000000;
			else if(chucvu=="NV") return luong + 7000000;
		}
		void xuat(){
			NS::xuat();
			cout << chucvu << " | "<< getTienluong() << endl;
		}
		long getLuong(){
			return luong;
		}
		string getChucvu(){
			return chucvu;
		}
};

class UngDung{
	int n;
	QL *ds;
	public:
		void nhap();
		void xuat();
		void TuoitreMax();
		void LuongMax();
};

void UngDung::nhap(){
	cout << "Nhap so nguoi quan li: "; cin >> n;
	ds = new QL[n];
	for(int i=0;i<n;i++){
		cout << "Thong tin nguoi quan li thu " << i+1 << endl;
		ds[i].nhap();
	}
}
void UngDung::xuat(){
	for(int i=0;i<n;i++){
		ds[i].xuat();
	}
}
void UngDung::TuoitreMax(){
	int min=ds[1].getTuoi();
	for(int i=0; i<n; i++){
		if(ds[i].getTuoi() < min) min=ds[i].getTuoi();
	}
	cout <<"\nNguoi co tuoi tre nhat: ";
	for(int i=0;i<n;i++){
		if(min == ds[i].getTuoi()){
			cout  << ds[i].getHoten() << endl;
		}
	}
}
void UngDung::LuongMax(){
	int max=0;
	for(int i=0; i<n; i++){
		if(ds[i].getTienluong() > max) max=ds[i].getTienluong();
	}
	cout << "Nguoi co luong cao nhat la: ";
	for(int i=0;i<n;i++){
		if(max == ds[i].getTienluong()){
			cout << ds[i].getHoten();
		}
	}
	
}
int main(){
	UngDung x;
	x.nhap();
	x.xuat();
	x.TuoitreMax();
	x.LuongMax();
}