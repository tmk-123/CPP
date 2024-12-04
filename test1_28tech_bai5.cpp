#include<bits/stdc++.h>

using namespace std;

class Student {
private:
    string MaSinhVien, HoTen, NgaySinh, Lop;
    double Gpa;
public:
    Student() {}
    Student(string a, string b, string c, string d, double e) : MaSinhVien(a), HoTen(b), NgaySinh(c), Lop(d), Gpa(e){}

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

    double getGpa() {
        return Gpa;
    }

    string getNgaySinh() {
        stringstream ss(NgaySinh);
        string word, s;
        while (getline(ss, word, '/')) {
            s.insert(0, word);
        }
        return s;
    }

    string getMa() {
        return MaSinhVien;
    }

    void printInformation() {
        cout << MaSinhVien << " " << HoTen << " " << NgaySinh << " " << Lop << " " << fixed << setprecision(2) << Gpa << endl;
    }
};

bool compare(Student a, Student b) {
    if (a.getNgaySinh() == b.getNgaySinh()) return a.getMa() < b.getMa();
    return a.getNgaySinh() < b.getNgaySinh();   
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
