#include <iostream>
#include <string>
#include <iomanip>

#define ll long long

using namespace std;

class User {
protected:
	string username;
	string password;
public:
	User() {

	}
	User(string u, string p) {
		username = u;
		password = p;
	}
	void print() {
		cout << username << " " << password << endl;
	}
};

class Student : public User {
private:
	string studentId;
	string major;
public:
	Student() {
	}
	Student (string u, string p, string s, string m) : User(u, p) {;
		studentId = s;
		major = m;
	}
	void print() {
		User::print();
		cout << studentId << " " << major << endl;	
	}
};

int main() {
	Student student("B23DCCN437", "123", "B23DCCN", "123456");
	student.print();	
	return 0;
}


