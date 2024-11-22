#include<bits/stdc++.h>

using namespace std;

const double esp = 1e-9;

int main() {
    long double xR, yR, R;
    cin >> xR >> yR >> R;

    long long cnt = 0;
    long long xMin = ceil(xR - R);
    long long xMax = floor(xR + R);

    for (long long x = xMin; x <= xMax; x++) {
        long double distanceX = fabs(x - xR);
        if ((distanceX - R) < esp) {
            long double distanceY = sqrt(R * R - distanceX * distanceX);
            long long yMin = yR - distanceY;
            long long yMax = yR + distanceY;

            while (yMin <= yR + distanceY && (x - xR) * (x - xR) + (yMin - yR) * (yMin - yR) - R * R > esp) {
                yMin++;
            } 
            while (yMax >= yR - distanceY && (x - xR) * (x - xR) + (yMax - yR) * (yMax - yR) - R * R > esp) {
                yMax--;
            }

            cnt += yMax - yMin + 1;
        }
    }

    cout << cnt;
}