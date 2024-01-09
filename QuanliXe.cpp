#include<bits/stdc++.h>

using namespace std;

class NguoiThue{
	private:
		string ht;
		double gio;
	public:
		friend istream& operator >> (istream& , NguoiThue& );
		friend ostream& operator << (ostream& ,const NguoiThue& );
		int getGio(){
			return gio;
		}
};

istream& operator >> (istream& in, NguoiThue& nt){
	cout << "Nhap ho ten nguoi thue: "; fflush(stdin); getline(in, nt.ht);
	cout << "So gio thue: "; in>> nt.gio;
	return in;
}

ostream& operator << (ostream& out,const NguoiThue& nt){
	out << " " << nt.ht << " " << nt.gio << endl;
	return out;
}

class Thongtin{
	int n, m;
	NguoiThue *xedulich;
	NguoiThue *xetai;
	public:
		friend istream& operator >> (istream& , Thongtin& );
		friend ostream& operator << (ostream& ,const Thongtin& );	
		float TienXetai();	
		float TienXedulich();
};

istream& operator >> (istream& in, Thongtin& nt){
	cout << "Nhap danh sach thue xe du lich va xe tai: "; in >> nt.n >> nt.m;
	nt.xedulich= new NguoiThue[nt.n];
	nt.xetai= new NguoiThue[nt.m];
	for(int i=0;i<nt.n;i++){
		cout << "Nguoi thue xe du lich thu " << i+1 << endl;
		in >> nt.xedulich[i];
	} 
	for(int i=0;i<nt.m;i++){
		cout << "Nguoi thue xe tai thu " << i+1 << endl;
		in >> nt.xetai[i];
	} 
	return in;
}
ostream& operator << (ostream& out,const Thongtin& nt){
	float dulich[nt.n];
	for(int i=0;i<nt.n;i++) dulich[i]=0;
	for(int i=0;i<nt.n;i++){
		dulich[i]+= 250 + ((nt.xedulich[i].getGio()-1)*70);
	}
	for(int i=0;i<nt.n;i++){
		out << " " << nt.xedulich[i] << "Thanh tien la: " << dulich[i] << endl;
	}
	
	float tai[nt.m];
	for(int i=0;i<nt.m;i++) tai[i]=0;
	for(int i=0;i<nt.m;i++){
		tai[i]+= 220 + ((nt.xetai[i].getGio()-1)*85);
	}
	for(int i=0;i<nt.m;i++){
		out << " " << nt.xetai[i] << "Thanh tien la: " << tai[i] << endl;
	}
	return out;
}

int main()
{
	Thongtin x;
	cin >> x;
	cout << x;
}