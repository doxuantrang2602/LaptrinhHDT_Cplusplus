#include<bits/stdc++.h>

using namespace std;

//class HCN{
//	double cd, cr;
//	public:
//		float tinhdt(){
//			return cd*cr;
//		}
//		HCN(){
//			cr=4;
//			cd=7.5;
//		}
//		HCN(const double& a){
//			cd=a; cr=5;
//		}
//		HCN(const double cd=7.5, const double cr=4){
//			cd=a; cr=b;
//		}
//};
//
//HCN::HCN(const double&a, const double &b){
//	cd=a; cr=b;
//}

class SoPhuc{
	float a, b;
	public:
		SoPhuc(const float &pt=1, const float &pa=1){
			a=pt;
			b=pa;
		}
		friend istream& operator >> (istream& , SoPhuc& );
		friend ostream& operator << (ostream& , const SoPhuc& );
};

//istream& operator >> (istream& in, SoPhuc& sp){
//	cout << "Nhap phan thuc va phan ao: "; in >> sp.a >> sp.b;
//	return in;
//}

ostream& operator << (ostream& out, const SoPhuc& sp){
	out << " " << sp.a << " +i" << sp.b << endl;
	return out;
}

int main(){
	SoPhuc c1(3,5.5), c2(2,3);
	//cin >> x;
	cout << c1 << endl <<c2;
}