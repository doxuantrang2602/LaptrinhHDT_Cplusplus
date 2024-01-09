#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class Diem{
	float x;
	float y;
	public:
		friend istream &operator >> (istream& ,Diem& );
		friend ostream &operator << (ostream& ,Diem& );
		float Tinh(Diem& a, Diem& b){
			float T;
			T = sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
			return T;
		}
};
istream &operator >> (istream& in,Diem& d){
	cout << "Nhap hoanh do: "; in >> d.x;
	cout << "Nhap tung do: "; in >> d.y;	
	return in;	
}
ostream &operator << (ostream& out,Diem& d){
	out << "(" << d.x << "," << d.y << ") " << endl;
	return out;
}

class UngDung{
	int n;
	Diem *ds;
	public:
		friend istream &operator >> (istream& ,UngDung& );
		friend ostream &operator << (ostream& ,UngDung& );	
		void DGK(){
			float gk=0;
			for(int i=1;i<n-1;i++){
				gk+= ds[i].Tinh(ds[i],ds[i+1]);
			}
			cout << "Do dai duong gap khuc (2,..,n,1) la: " << gk+ds->Tinh(ds[0],ds[n-1]);
		}
};
istream &operator >> (istream& in,UngDung& d){
	cout << "Nhap n: "; in >> d.n;
	d.ds = new Diem[d.n];
	for(int i=0;i<d.n;i++){
		cout << "Toa do diem thu " << i+1 << endl;
		in >> d.ds[i];
	}
	return in;
}
ostream &operator << (ostream& out,UngDung& d){
	for(int i=0;i<d.n;i++){
		out << d.ds[i];
	}
	return out;
}

int main(){
	UngDung x;
	cin >> x;
	cout << x;
	x.DGK();
	return 0;
}
