#include <bits/stdc++.h>
#define se second
#define fi first
#define endl '\n'
using ll = long long;

using namespace std;

int a(int n){
	if(n==1) return 5;
	if(n==2) return 0;
	else return a(n-1) + 6*a(n-2) ;
}

int main(){
	cout << a(5);
	return 0;
}
