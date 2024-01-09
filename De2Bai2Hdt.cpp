#include<bits/stdc++.h>

using namespace std;

class Diem{
	int x, y;
	public:
		void nhap(){
			cout << "Nhap hoanh do: "; cin >>x;
			cout << "Nhap tung do: "; cin >>y;
		}
		void xuat(){
			cout << "(" << x << "," << y << ")";
		}
		void dodai(Diem a, Diem b){
			float dt=0;
			dt = sqrt(pow(a.x-b.x,2) + pow(a.y-b.y));
		}
};

class UngDung{
	int n;
	Diem *ds;
	public:
		void nhap(){
			cout << "Nhap so diem: "; cin >> n;
			ds = new Diem[n];
			for(int i=0;i<n;i++){
				ds[i].nhap();
			}
		}
		void gapkhuc(){
			int gk=0;
			for(int i=0;i<n;i++){
				gk += ds[i].dodai(ds[i], ds[i+1]);
			}
			cout << "Do dai duong gap khuc: " << gk;
		}
};

int main(){
	UngDung x;
	x.nhap();
	x.gapkhuc();
	return 0;
}