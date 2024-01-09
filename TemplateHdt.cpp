#include<bits/stdc++.h>

using namespace std;

template <class T>
void nhap(int &n, T *&ds)
{
	cout << "\nNhap so luong: "; cin >> n;
	ds = new T[n+1];
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap ds" << i << ": ";
		cin >> ds[i];
	}
}
template <class T>
void xuat(const int &n, T *ds)
{
	for (int i = 1; i <= n; i++)
	{
		cout << ds[i] << "  ";
	}
	cout << endl;
}

template <class T>
void sapxep(int &n, T *&ds)
{
	T tg;
	for (int i = 1; i < n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			if (ds[j] < ds[i])
			{
				tg = ds[i];
				ds[i] = ds[j];
				ds[j] = tg;
			}
		}
	}
}

class ToaDo{
	float x,y;
	friend istream &operator >> (istream &cin, ToaDo &A)
	{
		cout << endl;
		cout << "Nhap hoanh do: "; cin >> A.x;
		cout << "Nhap tung do: "; cin >> A.y;
		return cin;
	}
	friend ostream &operator << (ostream &cout, const ToaDo &A)
	{
		cout << "(" << A.x << ", " << A.y << ")" << "  ";
		return cout;
	}
};

class ThiSinh{
	string ht, ma;
	float diem ;
	friend istream &operator >> (istream &cin, ThiSinh &A)
	{	
		cout << endl;
		cout << "Nhap ho ten: "; cin.ignore(1); getline(cin, A.ht);
		cout << "Nhap ma: "; getline(cin, A.ma);
		cout << "Nhap diem: "; cin >> A.diem;
		return cin;
	}
	friend ostream &operator << (ostream &cout, const ThiSinh &A)
	{
		cout << A.ht << "  " << A.ma << " " << A.diem << endl;
		return cout;
	}
};
int main()
{
	int n, m, *daynguyen;
	float *daythuc;
	nhap(n, daynguyen);
	xuat(n, daynguyen);

	nhap(m, daythuc);
	xuat(m, daythuc);

	ToaDo *daydiem;
	int k, h;
	nhap(k, daydiem);
	xuat(k, daydiem);
	
	ThiSinh *daythisinh;
	nhap(h, daythisinh);
	xuat(h, daythisinh);
	
}