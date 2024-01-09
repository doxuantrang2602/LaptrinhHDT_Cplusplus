#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

class DaThuc{
	private:
		int bac;
		int *hs;
	public:
		// Ham tao khong doi
		DaThuc(){
			
		}
		// Ham tao co doi
		DaThuc(int bac, int *hs=NULL){
			this->bac=bac;
			this->hs=new int[bac];
		}
		friend istream& operator >> (istream& in, DaThuc& dt){
			cout << "Nhap bac= "; in >> dt.bac;
			dt.hs = new int[dt.bac+1];
			for(int i=0;i<=dt.bac;i++){
				cout << "Nhap a[" << i << "]= "; in >> dt.hs[i];
			}
			return in;
		}	
		friend ostream& operator << (ostream& out, DaThuc& dt){
			cout << "f(x)= ";
			out << dt.hs[0];
			for(int i=1;i<=dt.bac;i++){
				out << "+(" << dt.hs[i] <<")x^" << i;
			}
			cout << endl;
			return out;
		}
		friend DaThuc operator+(DaThuc P, DaThuc Q){
			int k=0;
			DaThuc A;
			A.bac = max(P.bac,Q.bac);
			A.hs = new int[A.bac+1];
			for(int i=0;i<=A.bac;i++){
				A.hs[i] = P.hs[i] + Q.hs[i];
				k++;
			}
			if(k<Q.bac){
				for(int i=Q.bac-k;i<=Q.bac;i++){
					A.hs[i]=Q.hs[i];
				}
			}
			if(k<P.bac){
				for(int i=P.bac-k;i<=P.bac;i++){
					A.hs[i]=P.hs[i];
				}
			}
			return A;
		}
		friend DaThuc operator-(DaThuc P, DaThuc Q){
			int k=0;
			DaThuc A;
			A.bac = max(P.bac,Q.bac);
			A.hs = new int[A.bac+1];
			for(int i=0;i<A.bac;i++){
				A.hs[i] = P.hs[i]-Q.hs[i];
				k++;
			} 
			if(k<Q.bac){
				for(int i=k-Q.bac;i<=Q.bac;i++){
					A.hs[i]=-Q.hs[i];
				}
			}
			if(k<P.bac){
				for(int i=k-P.bac;i<P.bac;i++){
					A.hs[i]=P.hs[i];
				}
			}
			return A;
		}
		int Tinh(int x){
			int S=0;
			for(int i=0;i<=bac;i++){
				S+= hs[i]*pow(x,i);
			}
			return S;
		}
		void Dao_Ham(){
			cout << endl;
			cout << "P'(x)= "; 
			cout << "0 + " << hs[1];
			for(int i=2;i<=bac;i++){
				cout << " + (" << i*hs[i] << ")x^" << i-1;
			}
			cout << endl;
			int d;
			cout << "Nhap d= "; cin >> d;
			int s=0;
			for(int i=0;i<=bac;i++){
				s+= i*hs[i]*pow(d,i-1);
			}
			cout << "=> f'(d)= " << s << endl;
		}
	// Ham huy
	~DaThuc(){
			
		}
};

int main(){
	DaThuc P;
	cin >> P;
	cout << "=> Da thuc P: \n";
	cout << P;
	DaThuc Q;
	cin >> Q;
	cout << "=> Da thuc Q: \n";
	cout << Q;
	cout << endl;
	cout << "=> Da thuc P+Q la: \n";
	DaThuc R;
	R=P+Q;
	cout << R;
	cout << endl;
	cout << "=> Da thuc P-Q la: \n";
	DaThuc T=P-Q;
	cout << T;
	cout << endl;
	// Tinh S=1/(P(d1)-Q(d2))
	int d1,d2;
	cout << "Nhap d1= "; cin >> d1;
	cout << "Nhap d2= "; cin >> d2;
	float S;
	S=(P.Tinh(d1)-Q.Tinh(d2));
	cout <<"=> S= "<< fixed <<setprecision(3) << 1/S << endl;
	P.Dao_Ham();
	return 0;
}
