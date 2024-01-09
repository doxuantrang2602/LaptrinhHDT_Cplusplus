#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class MaTran{
	private:
		int n;
		int **tp;
	public:
		friend istream& operator >> (istream& in, MaTran& m){
			cout << "Nhap n: "; in >> m.n;
			m.tp = new int*[m.n];
			for(int i=0;i<m.n;i++){
				m.tp[i] = new int[m.n];
			}
			for(int i=0;i<m.n;i++){
				for(int j=0;j<m.n;j++){
					in >> m.tp[i][j];
				}
			}
			return in;
		}
		friend ostream& operator << (ostream& out, MaTran& m){
			for(int i=0;i<m.n;i++){
				for(int j=0;j<m.n;j++){
					out <<" " << m.tp[i][j];
				}
				cout << endl;	
			}
			return out;
		}
};

int main(){
	MaTran x;
	cin >> x;
	cout << x;
	return 0;
}
