#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<long, vector<long>, greater<long>> minHeap;
    for (int i = 0; i < n; i++) minHeap.push(a[i]);

    long sum = 0;
    while (minHeap.size() > 1) {
        long first = minHeap.top();
        minHeap.pop();
        long second = minHeap.top();
        minHeap.pop();

        long n = first + second;
        sum += n;

        minHeap.push(n);
    }

    cout << sum << " " << minHeap.top() << endl;
}