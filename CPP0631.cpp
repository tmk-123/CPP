#include<iostream>
#include<map>
#include<string>

using namespace std;

int IDKH = 1, IDMH = 1, IDHD = 1;

class KhachHang;
class MatHang;
class HoaDon;

map<string, KhachHang> KH;
map<string, MatHang> MH;

class KhachHang{
private:
	string clientCode, clientName, gender, birthday, address;	
public:
	KhachHang(){};
	friend class HoaDon;
	friend istream& operator >> (istream& in, KhachHang &a){
		if (IDKH < 10) a.clientCode = "KH00" + to_string(IDKH++);
		else a.clientCode = "KH0" + to_string(IDKH++);

		getline(in >> ws, a.clientName);
		getline(in, a.gender);
		getline(in, a.birthday);
		getline(in, a.address);

		KH[a.clientCode] = a;
		return in;
	}
	string GetClientName(){
		return clientName;
	}
	string GetAddress(){
		return address;
	}
};

class MatHang{
private:
	string productCode, productName, unit;
	int buy, sell;
public:
	MatHang(){};
	friend class HoaDon;
	friend istream& operator >> (istream& in, MatHang &a){
		if (IDMH < 10) a.productCode = "MH00" + to_string(IDMH++);
		else a.productCode = "MH0" + to_string(IDMH++);

		getline(in >> ws, a.productName);
		getline(in, a.unit);
		in >> a.buy >> a.sell;

		MH[a.productCode] = a;
		return in;
	}
	string GetProductName(){
		return productName;
	}
	string GetUnit(){
		return unit;
	}
	int GetBuy(){
		return buy;
	}
	int GetSell(){
		return sell;
	}
};
class HoaDon{
private:
	string invoiceCode, clientCode, productCode;
	int quantity;
public:
	HoaDon(){};
	friend istream& operator >> (istream &in, HoaDon &a){
		if (IDHD < 10) a.invoiceCode = "HD00" + to_string(IDHD++);
		else a.invoiceCode = "HD0" + to_string(IDHD++);

		in >> a.clientCode >> a.productCode >> a.quantity;
		
		return in;
	} 
	friend ostream& operator << (ostream &out, HoaDon a){
		out << a.invoiceCode << " "
			<< KH[a.clientCode].GetClientName() << " "
			<< KH[a.clientCode].GetAddress() << " "
			<< MH[a.productCode].GetProductName() << " "
			<< MH[a.productCode].GetUnit() << " "
			<< MH[a.productCode].GetBuy() << " "
			<< MH[a.productCode].GetSell() << " "
			<< a.quantity << " "
			<< a.quantity * MH[a.productCode].GetSell() << endl; 
		return out;
	}
};
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
    
    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}