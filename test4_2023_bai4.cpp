#include<bits/stdc++.h>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    unordered_map<string, int> club;
    string s;
    while (getline(cin, s)) {
        string s1 = s.substr(0, s.find("-") - 1);
        string s2 = s.substr(s.find("-") + 2);

        string club1 = s1.substr(0, s1.rfind(" "));
        int n1 = stoi(s1.substr(s1.rfind(" ") + 1));

        string club2 = s2.substr(s2.find(" ") + 1);
        int n2 = stoi(s2.substr(0, s2.find(" ")));

        club[club1] += n1;
        club[club2] += n2;
    }

    vector<pair<string, int>> v(club.begin(), club.end());
    sort(v.begin(), v.end(), compare);
    for (auto x : v) {
        cout << x.first << " " << x.second << endl; 
    }
}