#include<bits/stdc++.h>

using namespace std;

class BraveQ {
public:
    int power, blood;
    string alive;
    BraveQ() {}
    BraveQ(int a, int b, string c) : power(a), blood(b), alive(c) {}

    void event(string s, int n) {
        if (power <= 0 || blood <= 0) {
            power = 0;
            blood = 0;
            alive = "DEAD";
            return;
        }

        if (s == "mushroom") {
            blood -= 15;
            power -= 2;
        }
        else if (s == "witch") {
            if (n >= power) {
                alive = "DEAD";
            }
            else power += 5;
        }
        else if (s == "pea") {
            blood += 10;
            power += 2;
        }
        else if (s == "soldier") {
            if (n < power) {
                blood += 5;
                power += 7;
            }
            else alive = "DEAD";
        }
        
        if (alive == "DEAD") {
            blood = 0;
            power = 0;
        }
    }
};

int main() {
    string s;
    getline(cin, s);
    int Power = stoi(s.substr(s.find(":") + 2));
    getline(cin, s);
    int Blood = stoi(s.substr(s.find(":") + 2));
    string Alive;
    cin >> Alive;
    BraveQ brave(Power, Blood, Alive);

    int t;
    cin >> t;
    while (t--) {
        getline(cin >> ws, s);
        if (s == "pea" || s == "mushroom") {
            brave.event(s, 0);
        }
        else {
            string t = s.substr(0, s.find(" "));
            int n = stoi(s.substr(s.find(" ") + 1));
            brave.event(t, n);
        }
        
        cout << "POWER : " << brave.power << endl;
        cout << "BLOOD : " << brave.blood << endl;
        cout << brave.alive << endl;
        cout << "--------------------" << endl;
    }
}