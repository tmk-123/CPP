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
        vector<string> v;

        while (ss >> word) {
            v.push_back(word);
        }

        string t;
        for (int i = v.size() - 1; i >= 0; i--) {
            t += v[i];
            t += " ";
        }
        t.pop_back();

        cout << t << endl;
    }
}