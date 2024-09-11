#include <bits/stdc++.h>
using namespace std;

int A[11][1000001], B[11][1000001];

void calc(int as, int abs, int bs, int bbs) {
    int a = as; int b = bs;
    if (abs > 0) a--;
    if (bbs > 0) b--;
    if (a <= b) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    int A_swap = 0;
    int A_bottom_swap = 0;
    int B_swap = 0;
    int B_bottom_swap = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if (c == 'A') {
                A[i][j] = 1;
            } else {
                A[i][j] = -1;
                A_swap++;
                if (i == n) A_bottom_swap++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if (c == 'A') {
                B[i][j] = 1;
                B_swap++;
                if (i == n) B_bottom_swap++;
            } else {
                B[i][j] = -1;
            }
        }
    }
    calc(A_swap, A_bottom_swap, B_swap, B_bottom_swap);

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int a_t = A[a1][a2];
        int b_t = B[b1][b2];

        if (a_t != b_t) {
            // A는 B 주고 B는 A 준다
            if (a_t == -1 && b_t == 1) {
                A_swap--;
                B_swap--;
                if (a1 == n) {
                    A_bottom_swap--;
                }
                if (b1 == n) {
                    B_bottom_swap--;
                }
            } else {
                A_swap++;
                B_swap++;
                if (a1 == n) {
                    A_bottom_swap++;
                }
                if (b1 == n) {
                    B_bottom_swap++;
                }
            }
            A[a1][a2] = b_t;
            B[b1][b2] = a_t;
        }
        calc(A_swap, A_bottom_swap, B_swap, B_bottom_swap);
    }

    return 0;
}

