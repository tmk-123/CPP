#include<bits/stdc++.h>

using namespace std;

class Club {
public:
    string id, name;
    int matches, points, diff;
    Club() {}
    Club(string i, string n, int m, int d, int p) : id(i), name(n), matches(m), diff(d), points(p) {}
};

bool compare(Club a, Club b) {
    if (a.points == b.points) {
        if (a.diff == b.diff) return a.name < b.name;
        return a.diff > b.diff;
    }
    return a.points > b.points;
}

int main() {
    Club ds[20];
    string s;
    for (int i = 0; i < 20; i++) {
        getline(cin >> ws, s);
        string Id;
        cin >> Id;
        string Name;
        getline(cin >> ws, Name);
        int Matches, Diff, Points;
        cin >> Matches >> Diff >> Points;
        getline(cin >> ws, s);

        ds[i] = Club(Id, Name, Matches, Diff, Points);
    }

    while (getline(cin >> ws, s)) {
        string s1 = s.substr(0, s.find("-") - 1);
        string s2 = s.substr(s.find("-") + 2);

        string club1 = s1.substr(0, s1.rfind(" "));
        int n1 = stoi(s1.substr(s1.rfind(" ") + 1));

        string club2 = s2.substr(s2.find(" ") + 1);
        int n2 = stoi(s2.substr(0, s2.find(" ")));

        for (int i = 0; i < 20; i++) {
            if (club1 == ds[i].name) {
                ds[i].diff += n1 - n2;
                ds[i].matches++;
                if (n1 > n2) ds[i].points += 3;
                else if (n1 == n2) ds[i].points += 1;
            } 
            if (club2 == ds[i].name) {
                ds[i].diff += n2 - n1;
                ds[i].matches++;
                if (n1 < n2) ds[i].points += 3;
                else if (n1 == n2) ds[i].points += 1; 
            }
        }
    }

    sort(ds, ds + 20, compare);

    for (int i = 0; i < 20; i++) {
        cout << "#" << i + 1 << " " << ds[i].id << " " << ds[i].name << " " << ds[i].matches << " " << ds[i].diff << " " << ds[i].points << endl;
        cout << "------------------" << endl;
    }
}