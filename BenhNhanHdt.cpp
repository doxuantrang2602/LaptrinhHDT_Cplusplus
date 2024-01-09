#include<bits/stdc++.h>

using namespace std;

class Nguoi{
	private:
		string ht;
		int tuoi;
		string que;
	public:
		void nhap(){
			cout << "Nhap ho ten: "; fflush(stdin); getline(cin,ht);
			cout << "Nhap tuoi: "; cin >> tuoi;
			cout << "Nhap que quan: "; fflush(stdin); getline(cin,que);
		}
		void xuat(){
			cout << ht << " | " << tuoi << " "
		}
}
int main(){
	
}