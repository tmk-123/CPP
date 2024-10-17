#include<iostream>

#define ll long long

using namespace std;

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    int t;
    cin >> t;
    while (t--){
        ll a, x, y;
        cin >> a >> x >> y;

        for (int i = 0; i < gcd(x, y); i++){
            cout << a;
        }
        cout << endl;
    }  
}