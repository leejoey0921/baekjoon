#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define MAX 1000001

int main() {

    int n, m; cin >> n >> m;

    pii traps[n];
    fill_n(traps, n, pii{-MAX, MAX});

    for (int i = 0; i < m; i++) {
        int c, x, h; cin >> c >> x >> h;
        pii cur = traps[x];
        if (c == 0) {
            traps[x] = {max(h, cur.first), cur.second};
        } else {
            traps[x] = {cur.first, min(h, cur.second)};
        }
    }

    int lowest = 0;
    for (int i = 1; i < n; i++) {
        pii cur = traps[i];
        if (cur.first >= cur.second-1) {
            cout << "adios";
            return 0;
        }
        if (lowest - 1 >= cur.second) {
            cout << "adios";
            return 0;
        }
        lowest = max(lowest-1, cur.first+1);
    }
    if (lowest > 1) {
        cout << "adios";
        return 0;
    }

    cout << "stay";

    return 0;
}