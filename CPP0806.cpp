#include<bits/stdc++.h>

using namespace std;

class KhachHang;
class MatHang;

// không dùng unordered_map được bởi vì cần có constructor
map<int, KhachHang> KH;
map<int, MatHang> MH;

class KhachHang {
public:
    int code;
    string name, gender, birthday, address;
};

class MatHang {
public:
    int code;
    string name, unit;
    long long buy, sell;
};

string formatStr(string s) {
    stringstream ss(s);
    string word, res;

    while (ss >> word) {
        res += word;
        res += " ";
    }

    res.pop_back();
    return res;
}

void get_KH() {
    fstream fs;
    fs.open("KH.in");

    int n;
    fs >> n;

    for (int i = 0; i < n; i++) {
        int code = i + 1;
        string name, gender, birthday, address;

        getline(fs >> ws, name);
        getline(fs >> ws, gender);
        getline(fs >> ws, birthday);
        getline(fs >> ws, address);

        KH[i + 1] = {code, formatStr(name), formatStr(gender), formatStr(birthday), formatStr(address)}; 
    }
    
    fs.close();
}

void get_MH() {
    fstream fs;
    fs.open("MH.in");

    int n;
    fs >> n;

    for (int i = 0; i < n; i++) {
        int code = i + 1;
        string name, unit;
        long long buy, sell;

        getline(fs >> ws, name);
        getline(fs >> ws, unit);

        fs >> buy >> sell;

        MH[i + 1] = {code, formatStr(name), formatStr(unit), buy, sell};
    }

    fs.close();
}

void show_HD() {
    fstream fs;
    fs.open("HD.in");

    int n;
    fs >> n;

    string clientCode, productCode;
    int quantity;

    for (int i = 0; i < n; i++) {
        cout << "HD" << setfill('0') << setw(3) << i + 1 << " ";

        fs >> clientCode >> productCode >> quantity;

        // &clientCode[2] là con trỏ trỏ đến vị trí thứ 2 của chuỗi, nghĩa là lấy từ 2 về cuối 
        int khIndex = stoi(&clientCode[2]);
        int mhIndex = stoi(&productCode[2]);

        cout << KH[khIndex].name << " "
            << KH[khIndex].address << " "
            << MH[mhIndex].name << " "
            << MH[mhIndex].unit << " "
            << MH[mhIndex].buy << " "
            << MH[mhIndex].sell << " "
            << quantity << " "
            << quantity * MH[mhIndex].sell << endl;
    }
    fs.close();
}
int main () {
    get_KH();
    get_MH();
    show_HD();
}