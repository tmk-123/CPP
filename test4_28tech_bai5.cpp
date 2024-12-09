#include<bits/stdc++.h>

using namespace std;

class Person {
public:
    string name, address;
    Person(string a, string b) : name(a), address(b) {}
};

class Student : public Person {
public:
    string program;
    int year;
    double fee;
    Student(string a, string b, string c, int d, double e) : Person(a, b), program(c), year(d), fee(e) {}
};

class Staff : public Person {
public:
    string school;
    double pay;
    Staff(string a, string b, string c, double d) : Person(a, b), school(c), pay(d) {}
};

bool compare1 (Student x,Student y) {
    if (x.fee == y.fee)
        return x.name < y.name; 
    return x.fee > y.fee; 
};

bool compare2 (Staff x, Staff y) {
    if (x.pay == y.pay)
        return x.name < y.name; 
    return x.pay > y.pay; 
};
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    getline(cin >> ws, s);

    vector<Student> a;
    for (int i = 0; i < n; i++) {
        string Name, Address, Program;
        int Year;
        double Fee; 
        getline(cin >> ws, Name);
        getline(cin >> ws, Address);
        getline(cin >> ws, Program);
        cin >> Year >> Fee;
        Student stu(Name, Address, Program, Year, Fee);
        a.push_back(stu);
        getline(cin >> ws, s);
    }

    vector<Staff> b;
    for (int i = 0; i < m; i++) {
        string Name, Address, School;
        double Pay;
        getline(cin >> ws, Name);
        getline(cin >> ws, Address);
        getline(cin >> ws, School);
        cin >> Pay;
        getline(cin >> ws, s);
        Staff st(Name, Address, School, Pay);
        b.push_back(st);    
    }

    sort(a.begin(), a.end(), compare1); 
    sort(b.begin(), b.end(), compare2);

    cout << "Student List :" << endl;
    for (auto student : a) {
        cout << "-----------------" << endl;
        cout << "Full Name : " << student.name << endl;
        cout << "Address : " << student.address << endl;
        cout << "Program : " << student.program << endl;
        cout << "Year : " << student.year << endl;
        cout << "Fee : " << fixed << setprecision(0) << student.fee << " $" << endl;
    }
    cout << "-----------------" << endl;

    cout << "Staff List :" << endl;
    for (auto staff : b) {
        cout << "-----------------" << endl;
        cout << "Full Name : " << staff.name << endl;
        cout << "Address : " << staff.address << endl;
        cout << "School : " << staff.school << endl;
        cout << "Pay : " << fixed << setprecision(0) << staff.pay << " $" << endl;
    }
    cout << "-----------------" << endl;
    
    return 0;
}