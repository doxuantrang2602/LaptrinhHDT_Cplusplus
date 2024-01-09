#include<bits/stdc++.h>

using namespace std;

class laptop{
	private:
		string model,hsx;
		long gia;
		int tgbh;
	public:
		friend istream & operator>>(istream &, laptop&);
		friend ostream & operator<<(ostream &, const laptop&);
		long getgia()
		{
			return gia;
		}
		string gethsx()
		{
			return hsx;
		}
}; 
istream & operator>>(istream &in, laptop& lp){
	cout<<"nhap model ";in.ignore(1); getline(in,lp.model);
	cout<<"nhap hang san xuat "; getline(in,lp.hsx);
	cout<<"nhap gia "; in >> lp.gia;
	cout<<"nhap thoi gian bao hanh "; in >> lp.tgbh;
	return in;
}
ostream& operator<<(ostream &out, const laptop&lp){
	out<<lp.model<<" "<<lp.hsx<<" "<<lp.gia<<" "<<lp.tgbh<<endl;
	return out;
}
class Ungdung{
	int n;
	laptop *ds;
	public:
	friend istream & operator>>(istream&,Ungdung&);
	friend ostream& operator<<(ostream&, const Ungdung&);
	void sapxep();
	void timkiem(const long &, const string &);	
};
istream & operator>>(istream& in, Ungdung& lp){
	cout<<"nhap n ";in>>lp.n;
	lp.ds= new laptop[lp.n];
	for(int i=0;i<lp.n;i++){
		cout<<"nhap thong tin cho laptop thu "<<i+1<<"\n";
		in >> lp.ds[i];
	}
	return in;
}
ostream& operator<<(ostream&out, const Ungdung&lp){
	for(int i=0;i<lp.n;i++) out<<lp.ds[i];
	return out;
}
void Ungdung::sapxep(){
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if(ds[i].getgia()>ds[j].getgia())
			{
				laptop x=ds[i];
				ds[i]=ds[j];
				ds[j]=x; 
			}
	}
}
void Ungdung::timkiem(const long &gia, const string &hsx){
	bool kq=false;
	for(int i=0;i<n;i++)
	{
		if(ds[i].getgia()<=gia && ds[i].gethsx()==hsx)
		{
			cout<<ds[i];
			kq=true;	
		}	
	}
	if(!kq) cout<<"\nkhong tim thay"; 
}
int main(){
	Ungdung x;
	cin >> x;
	x.sapxep();
	cout << x;
	x.timkiem(18000000,"Dell");
}