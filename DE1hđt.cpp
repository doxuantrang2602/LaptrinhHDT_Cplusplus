#include <iostream>
using namespace std;

struct PhanSo {
	int tu, mau;
};

istream& operator >> (istream & is, PhanSo & m) {
	is >> m.tu >> m.mau;
	return is;
}

ostream& operator << (ostream & os, PhanSo m) {
	os << m.tu << "/" << m.mau;
	return os;
}


void Rutgon(PhanSo & m) {
	int d = UCLN(m.tu, m.mau);
	m.tu /= d;
	m.mau /= d;
}

bool operator > (PhanSo m, PhanSo n) {
	if (m.tu / m.mau > n.tu / n.mau)
		return true;
	return false;
}

int main () {
	int d , bdem = 1;
	PhanSo A[100];
	while (cin >> A[bdem]) {
		Rutgon(A[bdem]);
		++bdem;
	}
	PhanSo K = A[1];
	for (int i = 2; i < bdem; i++) {
		if (K > A[i]){
			K=A[i];
		}
	}
	cout << K;
	return 0;
}