#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int L, R;
};

bool compare(Segment a, Segment b) {
    if (a.R == b.R) return a.L < b.L; 
    return a.R < b.R; 
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].L >> segments[i].R;
    }
    
    sort(segments.begin(), segments.end(), compare);
    
    int count = 0; 
    int lastEnd = segments[0].R;

    for (int i = 1; i < n; i++) {
        if (segments[i].L < lastEnd) {
            count++;
        }
        else lastEnd = segments[i].R;
    }
    
    cout << count;
    return 0;
}
