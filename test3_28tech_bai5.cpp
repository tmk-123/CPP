#include<bits/stdc++.h>

using namespace std;

class BraveQ {
public:
    int Power, Blood;
    string Alive;
    BraveQ(int p, int q, string a) : Power(p), Blood(q), Alive(a) {}

    void handleEvent(string event, int enemyPower) {
        if (Alive == "DEAD") {
            return;
        }

        if (event == "mushroom") {
            Blood -= 15;
            Power -= 2;
        }
        else if (event == "witch") {
            if (enemyPower >= Power) {
                Power = 0;
                Blood = 0;
                Alive = "DEAD";
            } else {
                Power += 5;
            }
        } 
        else if (event == "pea") {
            Blood += 10;
            Power += 2;
        } 
        else if (event == "soldier") {
            if (enemyPower >= Power) {
                Power = 0;
                Blood = 0;
                Alive = "DEAD";
            } else {
                Blood += 5;
                Power += 7;
            }
        }

        if (Blood <= 0 || Power <= 0) {
            Power = 0;
            Blood = 0;
            Alive = "DEAD";
        }
    }

     void printStatus() {
        cout << "POWER : " << Power << "\n";
        cout << "BLOOD : " << Blood << "\n";
        cout << Alive << "\n";
        cout << "--------------------\n";
    }
};

int main() {
    string s;
    cin >> s; cin >> s;
    int power;
    cin >> power;

    cin >> s; cin >> s;
    int blood;
    cin >> blood;

    string alive;
    cin >> alive;

    BraveQ brave(power, blood, alive);
    int n;
    cin >> n;
    while (n--) {
        string event;
        cin >> event;

        if (event == "witch" || event == "soldier") {
            int enemyPower;
            cin >> enemyPower;
            brave.handleEvent(event, enemyPower);
        } else {
            brave.handleEvent(event, 0);
        }

        brave.printStatus();
    }
}