#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class NhanVien{
	private:
		string ma,ht;
		double hsl;
	public:
		// Ham tao co doi
		NhanVien(string ma="", string ht="", double hsl=1){
			this->ma=ma;
			this->ht=ht;
			this->hsl=hsl;
		}
		// Ham tao sao chep
		NhanVien(const NhanVien &ob){
			this->ma=ob.ma;
			this->ht=ob.ht;
			this->hsl=ob.hsl;
		}
		// Ham toan tu gan
		void operator=(const NhanVien &ob){
			this->ma=ob.ma;
			this->ht=ob.ht;
			this->hsl=ob.hsl;
		}
		void nhap(){
			cout << "Nhap ma: "; fflush(stdin); getline(cin,ma);
			cout << "Nhap ho ten: "; fflush(stdin); getline(cin,ht);
			cout << "Nhap he so luong: "; cin >> hsl;
		}
		void xuat(){
			cout <<" " << ma << " | " << ht << " | " << hsl; 
		}
		double getHsl(){
			return hsl;
		}
};

class NhanVien1:public NhanVien{
	private:
		string phong;
	public:
		void nhap(){
			NhanVien::nhap();
			cout << "Nhap phong ban(A1,A2,A3): "; fflush(stdin); getline(cin,phong);
		}
		void xuat(){
			NhanVien::xuat();
			cout << " | " << phong << endl;
		}
		string getPhong(){
			return phong;
		}
};

class DanhSach{
	int n;
	NhanVien1 *ds;
	public:
		// ham tao co doi
		DanhSach(int m=0, NhanVien1 *ds1=NULL){
			n=m;
			ds=ds1;
		}
		// Ham tao sao chep
		DanhSach(const DanhSach& ob){
			n=ob.n;
			ds= new NhanVien1[ob.n];
			for(int i=0;i<ob.n;i++){
				ds[i]=ob.ds[i];
			}
		}
		friend istream &operator >> (istream& in, DanhSach& t){
			cout << "Nhap n: "; in >> t.n;
			t.ds = new NhanVien1[t.n];
			for(int i=0;i<t.n;i++){
				cout << "Nhap nhan vien thu " << i+1 << endl;
				t.ds[i].nhap();
			}
			return in;
		}
		friend ostream& operator << (ostream& out, DanhSach& t){
			for(int i=0;i<t.n;i++){
				t.ds[i].xuat();
			}
			return out;
		}
		void friend Giam_dan(DanhSach& ob){
			for(int i=0;i<ob.n-1;i++){
				for(int j=0;j<ob.n-i-1;j++){
					if(ob.ds[j].getHsl()<ob.ds[j+1].getHsl()){
						swap(ob.ds[j],ob.ds[j+1]);
					}
				}
			}
			cout << endl;
			cout << "Danh sach nhan vien giam dan theo hsl la: \n";
			for(int i=0;i<ob.n;i++){
				ob.ds[i].xuat();
			}
		}
		void friend thong_ke_phong_ban(DanhSach& ob){
			int s[3];
			cout <<endl;
			cout << "Thong ke nhan vien phong ban: \n";
			for(int i=0;i<3;i++){
				s[i]=0;
				for(int j=0;j<ob.n;j++){
					if(ob.ds[j].getPhong() == "A1") s[0]++;
					if(ob.ds[j].getPhong() == "A2") s[1]++;
					if(ob.ds[j].getPhong() == "A3") s[2]++;
				}
				cout << "Phong A" << i+1 << " co " << s[i] << " nhan vien" << endl;
			}
		}
		// Ham huy
		~DanhSach(){
			if(ds) delete(ds);
		}
};
int main(){
	DanhSach x;
	cin >> x;
	cout << x;
	Giam_dan(x);
	thong_ke_phong_ban(x);
	return 0;
}
