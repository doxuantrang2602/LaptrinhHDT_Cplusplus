#include<bits/stdc++.h>
using namespace std;
int t=1;
 
 
void viethoa(string &s){
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z') s[i]-=32;
	}
}
class GiangVien{
private:	
	string mgv;
	string ten;
	string mon;
	string tenviethoa;
public:
	GiangVien(){
	}
	void setten(string tenviethoa){
		this->tenviethoa=tenviethoa;
	}
	string getten(){
		return tenviethoa;
	}
	friend istream& operator>>(istream& in,GiangVien &a){
		if(t<10) a.mgv="GV0"+to_string(t);
		else a.mgv="GV"+to_string(t);
		t++;
		getline(cin,a.ten);
		a.tenviethoa=a.ten;
		viethoa(a.tenviethoa);
		getline(cin,a.mon);
		viethoa(a.mon);
		string s;
		s+=a.mon[0];
		for(int i=1;i<a.mon.size();i++){
			if(a.mon[i-1]==' '&&a.mon[i]!=' ') s+=a.mon[i];
		}
		a.mon=s;
		return in;
	}
	friend ostream& operator<<(ostream& out,GiangVien &a){
		cout<<a.mgv<<" "<<a.ten<<" "<<a.mon<<endl;
		return out;
	}
};
 
int main() {
	int n,q;
	cin>>n;
	GiangVien ds[n];
	cin.ignore();
	for(int i=0;i<n;i++) cin>>ds[i];
	cin>>q;
	string s[q];
	for(int i=0;i<q;i++){
		cin>>s[i];
		cout<<"DANH SACH GIANG VIEN THEO TU KHOA "<<s[i]<<":"<<endl;
		viethoa(s[i]);
		for(int j=0;j<n;j++){
			if(ds[j].getten().find(s[i])!=-1) cout<<ds[j];
		}
	}
	return 0;
}