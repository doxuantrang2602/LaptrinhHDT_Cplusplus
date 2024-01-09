#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class DayNguyen{
	int n;
	int *a;
	public:
		friend istream &operator >> (istream& , DayNguyen& );
		friend ostream &operator << (ostream& , DayNguyen& );
		friend void TBC(DayNguyen& );
		void max_le();
};

istream &operator >> (istream& in, DayNguyen& dn){
	cout << "Nhap n: "; in >> dn.n;
	dn.a = new int[dn.n];
	for(int i=0;i<dn.n; i++){
		cout << "Nhap a[" << i << "]= ";
		in >> dn.a[i];
	}
}

ostream &operator << (ostream& out, DayNguyen& dn){
	for(int i=0;i<dn.n;i++){
		out << dn.a[i] << " ";
	}
}

void TBC(DayNguyen& ob){
	int sum=0;
	int cnt=0;
	for(int i=0;i<ob.n;i++){
		if(ob.a[i]%2==0){
			sum +=ob.a[i];
			cnt++;
		}
	}
	if(cnt == 0) cout << "Khong co phan tu chan" << endl;
	else{
		cout << "TBC cac so chan vua nhap la: " << sum/cnt << endl;
	}	
}

void DayNguyen::max_le(){
	int dem =0;
	int maxx=-10e5;
	for(int i=0;i<n;i++){
		if(a[i]%2==1){
			dem++;
		}
	}
	if(dem == 0 ) cout << "Khong co phan tu le nao";
	else if(dem >0){
		for(int i=0;i<n;i++){
			if(a[i]%2 == 1 && a[i] > maxx){
				maxx = a[i];
		}
		}
		cout << "Phan tu le lon nhat la: " << maxx;
	}
	
}
int main(){
	DayNguyen x;
	cin >> x;
	cout << x;
	TBC(x);
	x.max_le();
	return 0;
}
