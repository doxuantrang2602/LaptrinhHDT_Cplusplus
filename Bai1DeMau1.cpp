#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class Diem{
	private:
		float x;
		float y;
	public:
		void nhap(){
			cout << "Nhap hoanh do: "; cin >> x;
			cout << "Nhap tung do: "; cin >> y;
		}	
		void xuat(){
			cout <<"(" <<x<<"," << y << ") ";		
		}
		float khoangcach(Diem &a){
			float T;
			T=sqrt(pow(a.x,2)+pow(a.y,2));
			return T; 
		}
		bool ktra(Diem &a,Diem &b){
			if(a.y>0 && b.y<0 || a.y<0 && b.y>0) return true;
			else return false;
		}
};

class DayDiem{
	int n;
	Diem *ds;
	public:
		void nhap(){
			cout << "Nhap so diem: "; cin >> n;
			ds = new Diem[n];
			for(int i=0;i<n;i++){
				cout <<"Toa do diem thu " << i+1 << endl;
				ds[i].nhap();
			}
		}
		void xuat(){
			for(int i=0;i<n;i++){
				ds[i].xuat();
			}
		}
		void Max(){
			float max=-10e5;
			for(int i=0;i<n;i++){
				if(ds[i].khoangcach(ds[i])>max){
					max = ds[i].khoangcach(ds[i]);
				}
			}
			cout << endl;
			cout << "=> Diem xa goc toa do nhat la: ";
			for(int i=0;i<n;i++){
				if(max == ds[i].khoangcach(ds[i])){
					ds[i].xuat();
				}
			}
		}
		void Cat_truc_hoanh(){
			int cnt=0;		
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(ds[i].ktra(ds[i],ds[j])){
						cnt++;
					}
				}
			}
			cout << endl;
			cout << "=> So doan thang cat truc hoanh la: " << cnt;
		}
};

int main(){
	DayDiem x;
	x.nhap();
	x.xuat();
	x.Max();
	x.Cat_truc_hoanh();
	return 0;
}
