#include<iostream>
#include<map>
#include<vector>
#include<cmath>

#define ll long long

using namespace std;

const ll MAX = 1e7 + 1;
vector<bool> p(MAX, 1); // bool chỉ tốn 1 byte nhưng int tốn 4 byte nên sẽ lập được mảng lớn hơn
vector<ll> prime;

void sang(){
    p[0] = p[1] = false;
    ll limit = sqrt(MAX);

    for (ll i = 2; i <= limit; i++){
        if (p[i]){
            prime.push_back(i);
            for (ll j = i * i; j < MAX; j += i)
                p[j] = false;          
        }
    }
    for (ll i = limit + 1; i < MAX; ++i) {
        if (p[i]) {
            prime.push_back(i);
        }
    }
}

int main(){
    sang();
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        map<ll, ll> myMap;

        for (ll x : prime){
            if (x * x > n) break;
            int count = 0;

            while (n % x == 0){
                myMap[x]++;
                n /= x;
            }

        }
        if (n > 1) myMap.insert({n, 1});

        for (auto it : myMap){
            cout << it.first << " " << it.second << endl;
        }
        cout << endl;
    }
}