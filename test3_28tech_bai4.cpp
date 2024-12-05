#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    string sum, maxSum;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            if (sum.length() == 0 && s[i] == '0') continue;
            sum.push_back(s[i]);
            
            if (sum.length() > maxSum.length()) maxSum = sum;
            else if (sum.length() == maxSum.length() && sum > maxSum) maxSum = sum;
        }
        else {
            sum = "";
        }
    }
    
    if (maxSum == "") cout << "0";
    else cout << maxSum;
}
