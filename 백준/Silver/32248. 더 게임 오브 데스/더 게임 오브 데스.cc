#include <bits/stdc++.h>
using namespace std;

typedef pair<long, long> pii;

int main() {

    long n; cin >> n;
    long t; cin >> t;

    long points[n+1];
    for (long i = 1; i <= n; i++) {
        long x; cin >> x;
        points[i] = x;
    }

    long passed[n+1];
    fill_n(passed, n+1, -1);

    long cur = 1;
    passed[1] = 0;
    long period = n;
    long offset = 0;
    for (long i = 1; i <= n; i++) {
        cur = points[cur];
        if (t < n && t == i) {
            cout << cur;
            return 0;
        }
        if (passed[cur] >= 0) {
            period = i - passed[cur];
            offset = passed[cur];
            break;
        }
        passed[cur] = i;
    }


    long remainder = (t - offset) % period;


    for (long i = 1; i <= n ;i++) {
        if (passed[i] == remainder + offset) {
            cout << i;
            break;
        }
    }


    return 0;
}