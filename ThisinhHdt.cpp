#include<bits/stdc++.h>

using namespace std;

class Quanly;


class Thisinh{
	friend class Quanly;
	private:
		int sbd;
		string ht;
		double diem;
		string truong;
	public:
		friend istream& operator >> (istream& , Thisinh&);
		friend ostream& operator << (ostream& , const Thisinh&);
		string gettruong(){
 			return truong;
		 }
		 double getdiem(){
		 	return diem;
		 }
		 int getsbd(){
		 	return sbd;
		 }
};
istream& operator >> (istream& in, Thisinh& ts){
	cout << "Nhap sbd: "; in >> ts.sbd; fflush(stdin);
	cout << "Nhap ho ten thi sinh: ";  getline(in,ts.ht);
	cout << "Nhap diem: "; in >> ts.diem; fflush(stdin);
	cout << "Nhap ten truong: "; getline(in,ts.truong); 
	return in;
}
ostream& operator << (ostream& out, const Thisinh& ts){
	out << " " << ts.sbd << " " << ts.ht << " " << ts.diem << " " << ts.truong << endl;
	return out;
}

class Quanly{
	private:
		int n;
		Thisinh *ds;
	public:
		friend istream& operator >> (istream& , Quanly&);
		friend ostream& operator << (ostream& , const Quanly&);
		void tongdiem();
		void Timkiem(const int &);
};
istream& operator >> (istream& in, Quanly& ts){
	cout << "Nhap n: "; in >> ts.n;
	ts.ds = new Thisinh[ts.n];
	for(int i=0;i<ts.n;i++){
		cout << "Nhap thong tin thi sinh thu" << i+1 << endl;
		in >> ts.ds[i];
	} 
	return in;
}
void Quanly::tongdiem(){
	float M;
	int k;
	double A[4]={0, 0, 0, 0};
	for(int i=0;i<n;i++){
		if(ds[i].gettruong() == "A1") A[1]+=ds[i].getdiem();
		if(ds[i].gettruong() == "A2") A[2]+=ds[i].getdiem();  
		if(ds[i].gettruong() == "A3") A[3]+=ds[i].getdiem();
	}
	cout << A[1] << " " <<  A[2] << " " << " " << A[3] << endl;
	M= max(A[1],max(A[2],A[3]));
	for(int i=1;i<4;i++){
		if(M==A[i]) k=i;
	}
	cout << "Truong A" << k << " co tong diem cao nhat" << endl;
}
void Quanly::Timkiem(const int &SBD){
	for(int i=0; i<n;i++){
		if(SBD == ds[i].getsbd()){
			cout << endl << ds[i];
		}
	}
}

int main()
{
	Quanly x;
	cin >> x;
	x.tongdiem();
	x.Timkiem(02);
}