#include<bits/stdc++.h>

using namespace std;

class SinhVien{
	private:
		string ht;
		string ns;
		double lt;
		double csdl;
		double tkw;
	public:
		friend class Soluong;
		friend istream& operator >> (istream& , SinhVien& );
		friend ostream& operator << (ostream& ,const SinhVien& );
		double getLT(){
			return lt;
		}
		double getCSDL(){
			return csdl;
		}
		double getTKW(){
			return tkw;
		}
		string getHT(){
			return ht;
		}
		long getDiem(){
			return (lt + csdl + tkw)/3;
		}
};

istream& operator >> (istream& in, SinhVien& sv){
	cout << "Nhap ho ten: "; fflush(stdin); getline(in, sv.ht);
	cout << "Nhap ngay sinh: "; fflush(stdin); getline(in, sv.ns);
	cout << "Nhap diem mon Lap trinh, Csdl, Tkweb: "; 
	in >> sv.lt >> sv.csdl >> sv.tkw;
	return in;
}

ostream& operator << (ostream& out,const SinhVien& sv){
	out << " " << sv.ht << " " << sv.ns << " " << sv.lt << " " << sv.csdl << " " << sv.tkw << endl;
	return out;
}

class Soluong{
	int n;
	SinhVien *ds;
	public:
		friend istream& operator >> (istream& ,Soluong& );
		friend ostream& operator << (ostream& ,const Soluong& );
		void KhoaLuan();
		void ChuyenDe();
};

istream& operator >> (istream& in,Soluong& sv){
	cout << "Nhap so sinh vien: "; in >> sv.n;
	sv.ds= new SinhVien[sv.n];
	for(int i=0; i<sv.n;i++){
		cout << "Nhap sinh vien thu " << i+1 << endl;
		in >> sv.ds[i];
	}
	return in;
}

ostream& operator << (ostream& out,const Soluong& sv){
	for(int i=0;i<sv.n;i++){
		out << sv.ds[i];
	}
	return out;
}

void Soluong::KhoaLuan(){
	cout << "Danh sach sinh vien duoc lam khoa luan: " << endl;
	for(int i=0;i<n;i++){
		if(ds[i].getDiem() >=8 && ds[i].getLT() >=5 && ds[i].getCSDL() >=5 && ds[i].getTKW() >=5){
			cout << " " << ds[i].getHT();
		}
	}
}

void Soluong::ChuyenDe(){
	cout << "Danh sach sinh vien duoc lam chuyen de: " << endl;
	for(int i=0;i<n;i++){
		if(ds[i].getLT() >=5 && ds[i].getCSDL() >=5 && ds[i].getTKW() >=5){
			cout << " " << ds[i].getHT();
		}
	}
}

int main()
{
	Soluong x;
	cin >> x;
	cout << x;
	x.KhoaLuan();
	x.ChuyenDe();
}