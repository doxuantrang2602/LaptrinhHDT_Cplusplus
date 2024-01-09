#include<bits/stdc++.h>

using namespace std;

class MT{
	private:	
		int n;
		int **tp;
	public:
		friend istream& operator >> (istream& ,MT& );
		friend ostream& operator << (ostream& , const MT& );
		friend MT operator + (MT A, MT B);
};

istream& operator >> (istream& in,MT& mt){
	cout << "Nhap cap cua ma tran: "; in >> mt.n;
	mt.tp= new int*[mt.n];
	for(int i=0;i<mt.n;i++){
		mt.tp[i]= new int[mt.n];
		for(int j=0;j<mt.n;j++){
			in >> mt.tp[i][j];
		}
	}
	return in;
}

ostream& operator << (ostream& out, const MT& mt){
	for(int i=0;i<mt.n;i++){
		for(int j=0;j<mt.n;j++){
			out << " " << mt.tp[i][j];
		}
		out << endl;
	}
	return out;
}

MT operator + (MT A, MT B){
	MT C=A;
	for(int i=0;i<A.n;i++){
		for(int j=0;j<A.n;j++){
			C.tp[i][j] = A.tp[i][j] + B.tp[i][j];
		}
	}
	return C;
}

int main(){
	MT x;
	cin >> x;
	cout << x; 
	MT y;
	cin >> y;
	cout << y;
	MT a = x + y;
	cout << a;
	return 0;
}