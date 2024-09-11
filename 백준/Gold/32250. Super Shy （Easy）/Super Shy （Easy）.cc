#include <bits/stdc++.h>
using namespace std;

int splits[3000001];

int split(int n) {
    if (splits[n] >= 0) return splits[n];

    if (n < 3) {
        splits[n] = 0;
        return 0;
    }

    int cnt = 1 + split((n-1)/2) + split(n/2);
    splits[n] = cnt;
    return cnt;
}


int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    if (n <= 2) {
        cout << 1; return 0;
    }

    fill_n(splits, 3000001, -1);


    int ans = 0;
    for (int i = 0; i < (n-1)/2; i++) {
        int cur = 1;
        int l = i;
        int r = n - 1 - i;
        if (l >= 2) {
            cur++;
            l--;
        }
        if (r >= 2) {
            cur++;
            r--;
        }

        cur += split(l) + split(r);
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}