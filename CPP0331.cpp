#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string string_sum(string a, string b){
    if (a.length() < b.length()) swap(a, b);
    while (a.length() != b.length()) b.insert(0, "0");
    string c;
    int memory = 0;

    for (int i = a.length() - 1; i >= 0; i--){
        int sum = (a[i] - '0') + (b[i] - '0') + memory;
        memory = sum / 10; 
        c.push_back(sum % 10 + '0');
    }
    
    if (memory > 0) c.push_back(memory + '0');
    reverse(c.begin(), c.end());    
    return c;
}

bool checkSumStringUtil(string s, int begin, int len1, int len2){
    string s1 = s.substr(begin, len1);
    string s2 = s.substr(begin + len1, len2);
    string s3 = string_sum(s1, s2);

    if (s3.length() > s.length() - len1 - len2 - begin) 
        return false; // khong con du cho de chen s3
    
    if (s3 == s.substr(begin + len1 + len2, s3.length())){
        if (begin + len1 + len2 + s3.length() == s.length())
            return true;
        return checkSumStringUtil(s, begin + len1, len2, s3.length());
    }

    return false;
}

string isSumString(string s){
    int n = s.length();

    for (int i = 1; i < n; i++){
        for (int j = 1; i + j < n; j++){
            if (checkSumStringUtil(s, 0, i, j)) return "Yes\n";
        }
    }

    return "No\n";
}
int main() {
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        cout << isSumString(s);
    }
}