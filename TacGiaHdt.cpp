#include<bits/stdc++.h>

using namespace std;

class Nguoi{
	private:
		string ht;
		int tuoi;
	public:
		// Viet ham tao, huy, toan tu gan, ham tao sao chep
		Nguoi(string ht="", int tuoi=24){
			this->ht=ht;
			this->tuoi=tuoi;
		}
		Nguoi(const Nguoi &ob){ // Ham tao sao chep
			this->ht=ob.ht;
			this->tuoi=ob.tuoi;
		}
		void operator=(const Nguoi &ob){ // Ham toan tu gan
			this->ht=ob.ht;
			this->tuoi=ob.tuoi;
		}
		~Nguoi(){
			
		}
		void nhap(){
			cout << "Nhap ho ten: "; fflush(stdin); getline(cin, ht);
			do{
				cout <<"Nhap tuoi: "; cin >> tuoi;
			}while(tuoi<0 || tuoi >120);
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

class TacGia_TacPham:public Nguoi{
	private:
		string tentp;
		string ma;
		int loai;
		long thuong;
	public:
		TacGia_TacPham(string ht="", int tuoi=24, string tentp="", string ma="", int loai=2, long thuong=2000): Nguoi(ht,tuoi){
			this->tentp=tentp;
			this->ma=ma;
			this->loai=loai;
			this->thuong=thuong;
		}
		TacGia_TacPham(const TacGia_TacPham &ob):Nguoi((Nguoi)ob){
			this->tentp=ob.tentp;
			this->ma=ob.ma;
			this->loai=ob.loai;
			this->thuong=ob.thuong;
		}
		void operator=(const TacGia_TacPham &ob){
			Nguoi::operator=((Nguoi)ob);
			this->tentp=ob.tentp;
			this->ma=ob.ma;
			this->loai=ob.loai;
			this->thuong=ob.thuong;
		}
		~TacGia_TacPham(){
			
		}
		int getLoai(){
			return loai;
		}
		long getThuong(){
			return thuong;
		}
		void nhap(){
			Nguoi::nhap();
			cout << "Nhap ten tp: "; fflush(stdin); getline(cin, tentp);
			cout << "Nhap ma tp: "; fflush(stdin); getline(cin, ma);
			do{
				cout << "Nhap loai(1-am nhac; 2-truyen ngan;...;5): "; cin >> loai;
			}while(loai < 1 || loai >5);
			
			cout << "Nhap tien thuong: "; cin >> thuong;
		}
		void xuat(){
			Nguoi::xuat();
			cout << tentp << " | " << ma << " | " << loai << " | " << thuong << " | ";
			switch(loai){
				case 1:{
					cout << "Am nhac "<< endl;
					break;
				}
				case 2:{
					cout << "Truyen ngan "<< endl;
					break;
				}
				case 3:{
					cout << "Tieu thuyet " << endl;
					break;
				}
				case 4:{
					cout << "Tho ca" << endl;
					break;
				}
				case 5:{
					cout << "Phim anh" << endl;
					break;
				}
			}
		}
};
class UngDung{
	int n;
	TacGia_TacPham *ds;
	public:
		UngDung(int m=0, TacGia_TacPham *ds1=NULL){
			n=m;
			ds=ds1;
		}
		UngDung(const UngDung &ob){
			n=ob.n;
			ds = new TacGia_TacPham[ob.n];
			for(int i=0;i<n;i++){
				ds[i]=ob.ds[i];
			}
		}
		~UngDung(){
			if(ds) delete(ds);
		}
		void nhap();
		void xuat();
		void tkloai();
		void tg_maxThuong();
};
void UngDung::nhap(){
	cout << "Nhap danh sach tac gia tac pham: "; cin >> n;
	ds= new TacGia_TacPham[n];
	for(int i=0;i<n;i++){
		cout << "Tac gia tac pham thu " << i+1 << endl;
		ds[i].nhap();
	}
}
void UngDung::xuat(){
	for(int i=0;i<n;i++){
		ds[i].xuat();
	}
}
void UngDung::tkloai(){
	long s[6];
	for(int i=1;i<=5;i++){
		s[i]=0;
		for(int j=0;j<n;j++){
			if(ds[j].getLoai() == i){
				s[i]+=ds[j].getThuong();
			}
		}
		cout <<"Loai " << i << " co tong tien thuong: " << s[i] << endl;
	}
}
void UngDung::tg_maxThuong(){
	long max=0;
	for(int i=0;i<n;i++){
		if(ds[i].getThuong() > max) max=ds[i].getThuong();
	}
	cout << "\nCac tac pham duoc thuong cao nhat: ";
	for(int i=0;i<n;i++){
		if(max==ds[i].getThuong()){
			cout << ds[i].getHoten();
		}
	}
}
int main(){
	UngDung x;
	x.nhap();
	x.xuat();
	x.tkloai();
	x.tg_maxThuong();
	return 0;
}