#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class TuyenSinh{
	private:
		string SBD,ht;
		double diem;
	public:
		// ham tao co doi
		TuyenSinh(string SBD="", string ht="", double diem=9){
			this->SBD=SBD;
			this->ht=ht;
			this->diem=diem;
		}
		void nhap(){
			cout << "Nhap SBD: "; fflush(stdin); getline(cin,SBD);
			cout << "Nhap ho ten: "; fflush(stdin); getline(cin,ht);
			cout << "Nhap diem: "; cin>> diem;
		}
		void xuat(){
			cout << " " << SBD << " | " << ht << " | " << diem << " | ";
		}		
		double getDiem(){
			return diem;
		}	
		string getHoten(){
			return ht;
		}
};

class OlympicTin:public TuyenSinh{
	private:
		string truong;
	public:
		void nhap(){
			TuyenSinh::nhap();
			cout << "Nhap ten truong(A1, A2, A3): "; fflush(stdin); getline(cin,truong);
		}
		void xuat(){
			TuyenSinh::xuat();
			cout << truong << endl;
		}	
		string getTruong(){
			return truong;
		}
};

class DanhSach{
	private:
		int n;
		OlympicTin *ds;
	public:
		friend istream& operator >> (istream& in, DanhSach& d){
			cout << "Nhap n: "; in >> d.n;
			d.ds = new OlympicTin[d.n];
			for(int i=0;i<d.n;i++){
				cout << "Nhap thi sinh thu " << i+1 << endl;
				d.ds[i].nhap();
			}
			return in;
		}	
		friend ostream &operator << (ostream& out, DanhSach& d){
			for(int i=0;i<d.n;i++){
				d.ds[i].xuat();
			}
			return out;
		}
		void Tong(){
			cout << endl;
			float s[10];
			for(int i=0;i<3;i++){
				s[i]=0;
				for(int j=0;j<n;j++){
					if(ds[j].getTruong() == "A1") s[0]+=ds[j].getDiem();
					if(ds[j].getTruong() == "A2") s[1]+=ds[j].getDiem();
					if(ds[j].getTruong() == "A3") s[2]+=ds[j].getDiem();
				}
				cout << "Truong A" << i+1 << " co tong so diem la " << s[i] << endl;
			}
			cout << endl;
			float min=10e5;
			for(int i=0;i<3;i++){
				if(s[i] < min) min = s[i];
			}
			for(int i=0;i<3;i++){
				if(min == s[i]){
					cout << "Truong A" << i+1 << " co so diem nho nhat !\n";
				}
			}
			cout << endl;
		}
		void Diem_Min(){
			for(int i=0;i<n-1;i++){
				for(int j=0;j<n-i-1;j++){
					if(ds[j].getDiem()>ds[j+1].getDiem()){
						swap(ds[j],ds[j+1]);
					}
				}
			}
			cout << "3 thi sinh co so diem nho nhat la: \n";
			for(int i=0;i<3;i++){
				ds[i].xuat(); 
			}
		}
};

int main(){
	DanhSach x;
	cin >> x;
	cout << x;
	x.Tong();
	x.Diem_Min();
	return 0;
}
