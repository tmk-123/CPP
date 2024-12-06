#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        string word;

        int a[2000] = {0};
        while (ss >> word) {
            if (word.length() > 1) {
                int x = s.find("x");
                int heso = stoi(word.substr(0, x));
                int mu = stoi(word.substr(x + 2));
                a[mu] += heso;
            }
        }

        int first = 0;
        for (int i = 0; i < 2000; i++) {
            if (a[i] > 0) {
                if (first) cout << " + ";
                cout << a[i] << "x^" << i;
                first = 1;
            }
        }  

        cout << endl;
    }

}