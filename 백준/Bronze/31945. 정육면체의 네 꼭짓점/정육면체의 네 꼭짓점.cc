#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    unordered_set<string> faces;

    faces.insert("0246");
    faces.insert("0145");
    faces.insert("0123");
    faces.insert("4567");
    faces.insert("2367");
    faces.insert("1357");

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string points = "";
        for (int j = 0; j < 4; j++) { 
            string c; cin >> c;
            points += c;
        };
        sort(points.begin(), points.end());

        if (faces.find(points) != faces.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
