#include<bits/stdc++.h>

using namespace std;


//Tim kiem theo gia va loai
// Chuyen thanh toan tu nhap xuat
class Giay{
	private:
		int ma;
		int loai;
		string xx;
		double gia;
	public:
		friend istream& operator >> (istream &, Giay &);
		friend ostream& operator << (ostream &,const Giay &);
		friend int getloai(Giay &x);	
};

istream& operator >> (istream &in, Giay &x){
	cout<<"Nhap ma: ";
	in >> x.ma;
	cout << "Nhap loai: ";
	in >> x.loai;
	cout << "Nhap xuat xu: ";
	in >> x.xx; in.ignore(); getline(in, x.xx);
	cout << "Nhap gia: ";
	in >> x.gia;
	return in;
}

ostream& operator << (ostream &out,const Giay &x){
	out << " " << x.ma << " " << x.xx << x.gia << endl; 
	switch(x.loai){
		case 1: {
			out<<"dep bet";
			break;
		}
		case 2: {
			out << "3cm";
			break;
		}
		case 3: {
			out << "5-7cm";
			break;
		}
		case 4:{
			out << ">=9cm";
			break;
		}
	}
}
getloai(Giay x){
	return x.loai;
}
class Ungdung{
	int n;
	Giay *ds;
	public:
	//	void nhap();
		friend istream& operator << (istream &, Giay &);
		void Thongke();
};

friend istream& operator << (istream &in, Giay &x){
	cout << "Nhap so giay dep: "; in >>x.n;
	ds=new Giay[n+1];
	for(int i=0;i<n;i++){
		cout << "Nhap thong tin giay dep thu: " << i+1 <<endl;
		ds[i].nhap();
	}
}
void Ungdung::Thongke(){
	int dem[5];
	for(int j=1;j<=4;j++){
		dem[j]=0;
		for(int i=0;i<n;i++){
			if(ds[i].getloai()==j) dem[j]++;
		}
	cout << "Loai" << j <<"co" << dem[j] <<"doi" << endl;	
	}
}
void Ungdung::Timkiem(const long&loai, const int &gia){
	bool k=false;
	for(int i=0;i<n;i++){
		if(ds[i].getloai()==loai && ds[i].gia<gia){
			cout << ds[i].nhap() << ds[i].xuat() << endl;
		}
	}
}

int main(){
	Ungdung x;
	x.nhap();
	x.Thongke();
	return 0;
}