#include<bits/stdc++.h>

using namespace std;

class Dathuc{
	private:
		int bac, d, giatri;
		int* heso;
	public:
		// Ham tao khong doi
		Dathuc(){
			this->bac = 0;
			this->heso=NULL;
		}
		// Ham tao co doi
		Dathuc(int bac){
			this->bac =bac;
			this->heso = new int[bac+1];  
		}
		// Ham tao sap chep
		Dathuc(const Dathuc&ob){
			this->bac=ob.bac;
			this->heso= new int[ob.bac + 1];
		}
		void nhap(){
			cout <<"Nhap bac cua da thuc: "; cin >> bac;
			heso = new int[bac+1];
			for(int i=0;i<=bac;i++){
				cout << "Nhap a[" << i << "]= "; cin >> heso[i];
			}
		}
		void in(){
			cout << heso[0];
			for(int i=1; i<=bac;i++){
				if(heso[i] > 0 ){
					cout << "+" << heso[i] << "x^" << i;
				}
				else cout << heso[i] << "x^" << i;
			}
			cout << endl << "Gia tri da thuc la: " << giatri;
		}
		void tinh(){
			giatri =0;
			for(int i=0; i<=bac; i++){
				giatri += heso[i] * pow(d,i);
			}
		}
		~Dathuc(){
			delete[] heso;
		}
};

int main(){
	Dathuc a;
	a.nhap();
	a.tinh();
	a.in();
	return 0;
}