#include<bits/stdc++.h>

using namespace std;

class Student {
private:
    string MaSinhVien, HoTen, NgaySinh, Lop;
    double Gpa;
public:
    Student() {}
    Student(string a, string b, string c, string d, double e) : MaSinhVien(a), HoTen(b), NgaySinh(c), Lop(d), Gpa(e) {}

    void chuanHoaTen() {
        stringstream ss(HoTen);
        string s, word;
        while (ss >> word) {
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.length(); i++)
                word[i] = tolower(word[i]);
            s += word;
            s += " ";
        }
        s.pop_back();
        HoTen = s;
    }

    void chuanHoaNgSinh() {
        if (NgaySinh[1] == '/') NgaySinh.insert(0, "0");
        if (NgaySinh[4] == '/') NgaySinh.insert(3, "0");
    }

    void printInformation() {
        cout << MaSinhVien << " " << HoTen << " " << NgaySinh << " " << Lop << " " << fixed << setprecision(2) << Gpa << endl;
    }

    string getLop() {
        return Lop;
    }

    string getSortedName() {
        int pos = HoTen.rfind(' ');
        return HoTen.substr(pos + 1);
    }
};

bool compare(Student a, Student b) {
    if (a.getLop() == b.getLop()) return a.getSortedName() < b.getSortedName();
    return a.getLop() < b.getLop();
}

int main() {
    int n;
    cin >> n;
    Student ds[n];
    string a, b, c, d;
    double e;

    for (int i = 0; i < n; i++) {
        cin >> a;
        getline(cin >> ws, b);
        cin >> c >> d >> e;
        ds[i] = Student(a, b, c , d, e);
        ds[i].chuanHoaNgSinh();
        ds[i].chuanHoaTen();
    }

    sort(ds, ds + n, compare);
    
    for (int i = 0; i < n; i++) {
        ds[i].printInformation();
    }
}
