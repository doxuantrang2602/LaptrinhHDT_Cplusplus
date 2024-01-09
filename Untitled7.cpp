#include<iostream>
#include<string.h>
#include <bits/stdc++.h>

using namespace std;
   
class NGUOI{
	string ht;
	int tt;
  public:
       string getht(){
       	    return ht;
	   }
	   
	   int gettt(){
	   	    return tt;
	   }
	   
	   void nhap();
	   void xuat();
};

void NGUOI::nhap(){
	cout<<"Nhap ten: ";cin.ignore(1);getline(cin,ht);
	cout<<"Nhap tuoi: ";cin>>tt;
	
}

void NGUOI::xuat(){
	cout<<" "<<ht<<" "<<tt << " ";
}

class QLNV : public NGUOI{
	int nam;
	int luong;
	
	public:
		int getnam(){
			return nam;
		}
		
		int getluong(){
			return luong;
		}
		
		void nhap();
		void xuat();
		void tb();
		void tkiem();
};

void QLNV::nhap(){
	NGUOI::nhap();
	cout<<"Nhap nam cong tac: ";cin>>nam;
	cout<<"Nhap luong: ";cin>>luong;
}

void QLNV::xuat(){
	NGUOI::xuat();
	cout<<"nam cong tac: "<<nam<<" luong:  "<<luong << endl;
}
class Danhsach{
	int n;
	QLNV *q;

	public:
		void nhapnv();
		void xuatnv();
		void tb();
		void tk();
};

void Danhsach::nhapnv(){
	int n;
	cout<<"Nhap so nhan vien: ";cin>>n;
	q = new QLNV[n];
	for(int i = 0 ; i < n ; i++){
		cout<<"Nhap vao sinh vien thu "<<i+1<<endl;
		q[i].nhap();
	}
}

void Danhsach::xuatnv(){
	for(int i=0; i<n; i++){
		q[i].xuat();
	}
}



int main(){
	Danhsach ds;
	ds.nhapnv();
	ds.xuatnv();
}
