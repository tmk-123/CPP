#include<bits/stdc++.h>

using namespace std;

class KhachHang {
public:
    string clientCode, clientName, gender, bd, address;
};

class MatHang {
public:
    string productCode, productName, unit;
    int buy, sell; 
};

class HoaDon {
public:
    string invoiceCode;
    KhachHang kh;
    MatHang mh;
    int quantity;
};

int main() {
    fstream fs;
    fs.open("KH.in");
    int n;
    fs >> n;
    vector<KhachHang> KH;
    for (int i = 0; i < n; i++) {
        KhachHang a;
        getline(fs >> ws, a.clientName);
        getline(fs >> ws, a.gender);
        getline(fs >> ws, a.bd);
        getline(fs >> ws, a.address);
        string s = to_string(i + 1);
        a.clientCode = "KH" + string(3 - s.length(), '0') + s;
        KH.push_back(a);
    }
    fs.close();

    fs.open("MH.in");
    int m;
    fs >> m;
    vector<MatHang> MH;
    for (int i = 0; i < m; i++) {
        MatHang a;
        getline(fs >> ws, a.productName);
        getline(fs >> ws, a.unit);
        fs >> a.buy >> a.sell;
        string s = to_string(i + 1);
        a.productCode = "MH" + string(3 - s.length(), '0') + s;
        MH.push_back(a);
    }
    fs.close();

    fs.open("HD.in");
    int k;
    fs >> k;

    vector<HoaDon> HD;
    for (int i = 0; i < k; i++) {
        HoaDon a;
        fs >> a.kh.clientCode >> a.mh.productCode >> a.quantity;
        string s = to_string(i + 1);
        a.invoiceCode = "HD" + string(3 - s.length(), '0') + s;

        for (auto x : KH) {
            if (x.clientCode == a.kh.clientCode) {
                a.kh = x;
                break;
            }
        }

        for (auto x : MH) {
            if (x.productCode == a.mh.productCode) {
                a.mh = x;
                break;
            }
        }
        HD.push_back(a);
    }
    fs.close();

    for (int i = 0; i < k; i++) {
        cout << HD[i].invoiceCode << " " << HD[i].kh.clientName << " " << HD[i].kh.address << " " << HD[i].mh.productName
             << " " << HD[i].mh.unit << " " << HD[i].mh.buy << " " << HD[i].mh.sell << " " << HD[i].quantity << " " 
             << HD[i].quantity * HD[i].mh.sell << endl;
    }
}