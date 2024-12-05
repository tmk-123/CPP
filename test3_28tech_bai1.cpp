#include<bits/stdc++.h>

using namespace std;

vector<bool> p(1000001, true);
void sang() {
    p[0] = p[1] = false;
    for (int i = 2; i <= 1000; i++) {
        if (p[i] == true)
            for (int j = i * i; j <= 1000000; j += i) p[j] = false;
    }
}

bool check(int n) {
    while (n > 0) {
        if (!p[n]) return false;
        n /= 10;
    }
    return true;
}
int main() {
    sang();
    int a, b;
    cin >> a >> b;

    int ok = 0;
    for (int i = a; i <= b; i++) {
        if (p[i] == true && check(i)) {
            ok = 1;
            cout << i << " ";
        }
    }

    if (!ok) cout << "28tech";
}
