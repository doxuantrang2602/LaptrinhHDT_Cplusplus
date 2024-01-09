#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class DaThuc{
	int bac;
	int *heso;
	public:
		friend istream &operator >> (istream &cin, DaThuc& dt){
			cout << "Nhap bac= "; cin >> dt.bac;
			dt.heso= new int[dt.bac+1];
			for(int i=0;i<=dt.bac;i++){
				cout << "Nhap heso[" << i << "]= ";
				cin >> dt.heso[i];
			}
			return cin;
		}
		friend ostream &operator << (ostream &cout, DaThuc& dt){
			cout << "f(x)= ";
			cout << dt.heso[0];
			for(int i=1;i<=dt.bac;i++){
				if(dt.heso[i]>0)
					cout << "+" << dt.heso[i] << "x^" << i;
				else cout << dt.heso[i] << "x^" << i;	
			}
			cout << endl;
			return cout;
		}
		friend void Tinh(DaThuc &a){
			int x;
			cout << "Nhap x: ";
			cin >> x;
			int F =0;
			for(int i=0;i<=a.bac;i++){
				F+=  a.heso[i]*pow(x,i);
			}
			cout << "=> Gia tri cua da thuc f(x) la: " << F << endl;
		}
		friend void Dao_Ham(DaThuc &ob){
			cout << "Dao ham f'(x)= ";
			cout << ob.heso[1]; 
			for(int i=2;i<=ob.bac;i++){
				if(i*ob.heso[i]>0) 
					cout << "+" <<  i*ob.heso[i] << "x^" << i-1;  
				else cout << i*ob.heso[i] << "x^" << i-1;	
			}
			cout << endl;
			int d;
			cout << "Nhap d= "; cin >> d;
			int s=0;
			for(int i=0;i<=ob.bac;i++){
				s+= i*ob.heso[i]*pow(d,i-1);
			}
			cout << "=> f'(d)= " << s << endl;
		}
};

int main(){
	DaThuc x;
	cin >> x;
	cout << x;
	Tinh(x);
	Dao_Ham(x);
	return 0;
}
