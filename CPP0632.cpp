#include<bits/stdc++.h>

using namespace std;

int cnt1 = 1, cnt2 = 1, cnt3 = 1;
class KhachHang;
class MatHang;
vector<KhachHang> KH;
vector<MatHang> MH;

class KhachHang {
public:
	string clientCode, clientName, gender, bd, address;

	friend istream& operator >> (istream& in, KhachHang& a) {
		getline(in >> ws, a.clientName);
		in >> a.gender >> a.bd;
		getline(in >> ws, a.address);
		string s = to_string(cnt1++);
		a.clientCode = "KH" + string(3 - s.length(), '0') + s;
		KH.push_back(a);
		return in;
	}
};

class MatHang {
public:
	string productCode, productName, unit;
	int buy, sell;

	friend istream& operator >> (istream& in, MatHang a) {
		getline(in >> ws, a.productName);
		getline(in >> ws, a.unit);
		in >> a.buy >> a.sell;
		string s = to_string(cnt2++);
		a.productCode = "MH" + string(3 - s.length(), '0') + s;
		MH.push_back(a);
		return in;
	}
};

class HoaDon {
public:
	string invoiceCode, client, product;
	int quantity, profit;
	KhachHang kh;
	MatHang mh;

	friend istream& operator >> (istream& in, HoaDon& a) {
		in >> a.client >> a.product >> a.quantity;
		string s = to_string(cnt3++);
		a.invoiceCode = "HD" + string(3 - s.length(), '0') + s;

		for (auto x : KH) {
			if (a.client == x.clientCode) {
				a.kh = x;
				break;
			}
		}

		for (auto x : MH) {
			if (a.product == x.productCode) {
				a.mh = x;
				break;
			}
		}
		a.profit = a.quantity * (a.mh.sell - a.mh.buy);

		return in;
	}

	friend ostream& operator << (ostream& out, HoaDon& a) {
		out << a.invoiceCode << " " << a.kh.clientName << " " << a.kh.address << " " << a.mh.productName << " " 
			<< a.quantity << " " << a.mh.sell * a.quantity << " " << a.profit << endl;

		return out;
	} 
};

bool compare(HoaDon a, HoaDon b) {
	return a.profit >= b.profit;
}

void sapxep(HoaDon dshd[], int k) {
	sort(dshd, dshd + k, compare);
}
int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];

    sapxep(dshd, K);

    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}