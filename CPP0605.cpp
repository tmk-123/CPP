#include<bits/stdc++.h>

using namespace std;

class PhanSo{
public:
    long long tu, mau;

    PhanSo(long long tu, long long mau){
        this->tu = tu;
        this->mau = mau;
    }

    friend istream& operator >> (istream &in, PhanSo &a){
        in >> a.tu >> a.mau;
        return in;
    }
    void rutgon(){
        long long ucln = __gcd(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }
    friend ostream& operator << (ostream &out, PhanSo &a){
        cout << a.tu << "/" << a.mau;
        return out;
    }
};

int main() {
	PhanSo p(1,1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}