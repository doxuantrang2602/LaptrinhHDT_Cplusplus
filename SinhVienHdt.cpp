#include<bits/stdc++.h>
using namespace std;
// class : Lop
// thuoc tinh : attribute
// Phuong thuc : method, behavior
// object : Doi tuong
// constructor: ham khoi tao
// destructor : ham huy
// This pointer
// setter getter
// - Encapsulation : Dong goi
// - Access modifer :
// - Private
// - Public
// - Protected
// SV001=>SV002=>SV003 : Static
// Friend function, friend class

class GiaoVien;
class SinhVien;


class SinhVien{
	friend class GiaoVien;
	private:
		string id, ten, ns;
		double gpa;
	public:
		SinhVien(); //contructor
		SinhVien(string, string, string, double);
		void nhap();
		void in(); 
		double getGPA();
		friend void ChuanHoa(SinhVien&);
		~SinhVien(); // ham huy
};
void ChuanHoa(SinhVien &a)
{
	string res= "";
	stringstream ss(a.ten);
	string token;
	while(ss >> token){
		res += toupper(token[0]);
		for(int i=1; i<token.length(); i++){
			res += tolower(token[i]);
		}
		res += " ";
	}
	res.erase(res.length()-1);
	a.ten =res;
}

//Implementation
SinhVien::SinhVien(){
	//cout << "Ham khoi tao duoc goi\n";
}
SinhVien::SinhVien(string id, string ten, string ns, double gpa){
	this->id = id;
	this->ten =ten;
	this->ns = ns;
	this->gpa = gpa;
}
SinhVien::~SinhVien(){
	//cout << "Doi tuong duoc huy tai day \n";
}
void SinhVien::nhap(){
	cout << "Nhap id: "; cin >> id;
	cin.ignore();
	cout << "Nhap ten: "; getline(cin, this->ten);
	cout << "Nhap ngay sinh: "; cin >> this->ns ;
	cout << "Nhap gpa: "; cin >> this->gpa;
}

void SinhVien::in(){
	cout << this->id << " " << this->ten << " " << this->ns << " " << fixed << setprecision(2) << this->gpa << endl;
}
double SinhVien::getGPA(){
	return this->getGPA();
}
bool cmp(SinhVien a, SinhVien b){
	return a.getGPA() > b.getGPA();
}

class GiaoVien{
	private:
		string khoa;
	public:
		void update(SinhVien&);
			
};

void GiaoVien::update(SinhVien&x)
{
	x.gpa = 3.2;
}


int main()
{
	int n; cin>>n;
	SinhVien a[100];
	GiaoVien b;
	for(int i=0;i<n;i++){
		a[i].nhap();
		ChuanHoa(a[i]);
		b.update(a[i]);
	}
	sort(a, a+n, cmp);
	for(int i=0;i<n;i++){
		a[i].in();
	}
	
	return 0;
}