#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        long cnt = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '8') cnt++;
            if (i <= s.length() - 2) {
                int n = stoi(s.substr(i, 2));
                if (n % 8 == 0 && n % 3 != 0) cnt++;  
            } 
            if (i <= s.length() - 3) {
                int n = stoi(s.substr(i, 3));
                if (n % 8 == 0) {
                    int sum = (s[i] - '0') + (s[i + 1] - '0') + (s[i + 2] - '0');
                    if (sum % 3 != 0) cnt++;
                    for (int j = i - 1; j >= 0; j--) {
                        sum += s[j] - '0';
                        if (sum % 3 != 0) cnt++;
                    }
                }
            }
        }

        cout << cnt << endl;
    }
}