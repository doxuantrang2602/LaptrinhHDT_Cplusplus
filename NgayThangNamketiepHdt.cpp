#include<bits/stdc++.h>
using namespace std;
 
struct date{
	int day,month,year;
};
 
bool namnhuan(date a){
	if(a.year%4==0&&a.year%100!=0 || a.year%400==0) return true;
	else return false;
}
void xuli(date &a){
	a.day++;
	if(a.month==1 || a.month==3||a.month==5 || a.month==7||a.month==8||a.month==10||a.month==12){
		if(a.day>31&&a.month==12){
			a.day=1; a.month=1; a.year++;
		}else if(a.day>31){
			a.month++;
			a.day=1;
		}
	}else if(a.month==2){
		if(a.day>28){
			if(namnhuan(a)==false || a.day>29){
				a.day=1; a.month++;
			}
		}
	}else{
		if(a.day>30){
			a.day=1; a.month++;
		}
	}
}
int main(){
	date a;
	string st;
	cin>>a.day>>st>>a.month>>st>>a.year;
	xuli(a);
	cout<<a.day<<"/"<<a.month<<"/"<<a.year<<endl;
	return 0;
}