#include<bits/stdc++.h>

using namespace std;

class NhanVien{
	private:
		string ma;
		string name;
	public:
		void nhap(){
			cout << "Nhap ma nhan vien: ";fflush(stdin); getline(cin, ma);
			cout << "Nhap ten nhan vien: ";fflush(stdin); getline(cin, name);
		}
		string getMa(){
			return ma;
		}
		string getName(){
			return name;
		}
		void in(){
			cout << " " << ma << " " << name << endl;
		}
};

class BienChe : public NhanVien{
	private:
		long nct;
		int HSL;
		float LCB;
	public:
		void nhap(){
			NhanVien::nhap();
			cout << "Nhap nam cong tac: "; cin >> nct;
			cout << "Nhap HSL: "; cin >> HSL;
			cout << "Nhap LCB: "; cin >> LCB;
		}
		long getNct(){
			return nct;
		}
		int getHSl(){
			return HSL;	
		}
		float getLCB(){
			return LCB;
		}
		double TinhLuong(){
			float pc;
			float a = HSL*LCB + pc;
			if(nct>10){
				pc =10;
			}
			else if(5<nct<=10){
				pc=7;
			}
			else if(1<=nct<5) pc =3;
			return a;
		}
		void in(){
			NhanVien::in();
			cout << nct << " " << HSL << " "<< fixed << setprecision(1) << LCB << " " << endl;
			cout << "Luong: " << TinhLuong() << endl;
		}
};

class UngDung{
	int n;
	BienChe *ds;
	public:
		friend istream& operator >> (istream& , UngDung& );
		friend ostream& operator << (ostream& , UngDung& );
		void TimNamCT();
		void TimTenNV();
};
istream& operator >> (istream& in, UngDung& bc){
	cout <<"Nhap so nhan vien: "; in >> bc.n;
	bc.ds = new BienChe[bc.n];
	for(int i=0;i<bc.n;i++){
		cout << "Nhap thong tin nhan vien thu " << i+1 << endl;
		bc.ds[i].nhap();
	}
	return in;
}

ostream& operator << (ostream& out, UngDung& bc){
	for(int i=0;i<bc.n;i++){
		bc.ds[i].in();
	}
	return out;
}

void UngDung::TimNamCT(){
	int Max=0;
	for(int i=0;i<n;i++){
		if(ds[i].getNct() < Max) 
		{
			Max = ds[i].getNct();
		}
	}
	for(int i=0;i<n;i++){
		if(Max == ds[i].getNct()) cout << "Nhan vien co so nam cong tac nhieu nhat la: " << ds[i].getName();
	}
}
void UngDung::TimTenNV(){
	string s;
	cout <<"Nhap ten nhan vien can tim: ";
	cin.ignore(); getline(cin, s);
	for(int i=0;i<n;i++){
		if(ds[i].getName()==s){
			ds[i].in();
		} 
	}
	
}
int main(){
	UngDung x;
	cin >> x;
	cout << x;
	x.TimNamCT();
	x.TimTenNV();
}


