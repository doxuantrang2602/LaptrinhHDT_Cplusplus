#include <bits/stdc++.h>
#include<algorithm>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class QLH{
	private:
		string ma, ten, xuatxu;
		int loai,sl;
	public:
		// Ham tao khong doi
		QLH(){
			
		}
		// Ham tao co doi
		QLH(string ma="", string ten="", string xuatxu="", int loai=3,int sl=10){
			this->ma=ma;
			this->ten=ten;
			this->xuatxu=xuatxu;
			this->loai=loai;
			this->sl=sl;
		}
		// Ham tao sao chep
		QLH(const QLH& ob){
			this->ma=ob.ma;
			this->ten=ob.ten;
			this->xuatxu=ob.xuatxu;
			this->loai=ob.loai;
			this->sl=ob.sl;
		}
		void nhap(){
			cout << "Nhap ma: "; fflush(stdin); getline(cin,ma);
			cout << "Nhap ten hang: "; fflush(stdin); getline(cin,ten);
			cout << "Nhap xuat xu: "; fflush(stdin); getline(cin,xuatxu);
			cout << "Nhap loai(1,2,3): "; cin >> loai;
			cout << "Nhap so luong: "; cin >> sl;
		}
		void xuat(){
			cout << ma << " | " << ten << " | " << xuatxu << " | " << loai << " | So luong: " << sl;
		}
		int getLoai(){
			return loai;
		}
};

class DienTu:public QLH{
	private:
		int tgbh;
	public:
		// Ham tao co doi
		DienTu(string ma="", string ten="", string xuatxu="", int loai=3,int sl=10,int tgbh=12):QLH(ma,ten,xuatxu,loai,sl){
			this->tgbh=tgbh;
		}
		void nhap(){
			QLH::nhap();
			cout << "Nhap tgbh: "; cin >> tgbh;
		}	
		void xuat(){
			QLH::xuat();
			cout << " | tgbh: " << tgbh << endl;
		}
		int getTgbh(){
			return tgbh;
		}
};

class DanhSach{
	int n;
	DienTu *ds;
	public:
		void nhap(){
			cout << "Nhap n: "; cin >> n;
			ds = new DienTu[n];
			for(int i=0;i<n;i++){
				cout << "Thong tin mat hang thu " << i+1 << endl;
				ds[i].nhap();
			}
		}
		void xuat(){
			for(int i=0;i<n;i++){
				ds[i].xuat();
			}
		}
		void Thong_ke(){
			int s[3];
			for(int i=0;i<3;i++){
				s[i]=0;
				for(int j=0;j<n;j++){
					if(ds[j].getLoai() == 1) s[0]++;
					if(ds[j].getLoai() == 2) s[1]++;
					if(ds[j].getLoai() == 3) s[2]++;
				}
				cout << "Loai " << i+1 << " co " << s[i] << " mat hang! " << endl;
			}
		}
		void Tim_Kiem(){
			int Max=-10e5;
			for(int i=0;i<n;i++){
				if(ds[i].getLoai() == 1){	
					if(ds[i].getTgbh() > Max){
						Max=ds[i].getTgbh();
					}	
				}
			}
			cout << "Hang Loai 1 co tgbh lau nhat la: \n";
			for(int i=0;i<n;i++){
				if(ds[i].getLoai() == 1 && Max == ds[i].getTgbh()){
					ds[i].xuat();
				}
			}
		}
};

int main(){
	DanhSach x;
	x.nhap();
	x.xuat();
	x.Thong_ke();
	x.Tim_Kiem();
	return 0;
}
