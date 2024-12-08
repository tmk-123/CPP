#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> ticket;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ticket.insert(x);
    }

    int customer[m];
    for (int i = 0; i < m; i++) cin >> customer[i];

    for (int i = 0; i < m; i++) {
        int max_price = customer[i];

        auto it = ticket.upper_bound(max_price);

        if (it == ticket.begin()) {
            cout << -1 << endl;
        }
        else {
            --it;
            cout << *it << endl;
            ticket.erase(it);
        }
    }
}