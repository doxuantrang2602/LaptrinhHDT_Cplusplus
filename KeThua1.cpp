#include<bits/stdc++.h>

using namespace std;
// is-a
// base class: class cha
// derived class: class con
// fuction overriding: ghi de`
class Person{
	private:
		string name;
		string address;
	public:
		Person(string name, string address){
			this->name = name;
			this->address = address;
		}
		void nhap(){
			getline(cin, name);
			getline(cin, address);
		}
		string getName(){
			return name;
		}	
		string getAddress(){
			return address;
		}
		void setName(string name){
			this->name = name;
		}
		void setAddress(string address){
			this->address = address;
		}
		void in(){
			cout << name << " " << address << " ";
		}
};

class Student : public Person{
	private:
		float gpa;
	public:
		Student(string name, string address, float gpa) : Person(name, address){
			this->gpa = gpa;
		}
		void nhap(){
			Person::nhap();
			cin >> gpa;
		}
		float getGpa(){
			return gpa;
		}
		void getGpa(float gpa){
			this->gpa = gpa;
		}
		void in(){
			Person::in();
			cout << fixed << setprecision(2) << gpa << endl;
		}
};

int main()
{
	Student s("Do Xuan Trang", "Ha Noi", 2.8);
	s.in();
}