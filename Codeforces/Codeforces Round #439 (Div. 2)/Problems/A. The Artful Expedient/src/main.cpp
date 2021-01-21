#include <bits/stdc++.h>

using namespace std;

bool in[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        in[a[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        in[b[i]] = true;
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i ^ j) <= 2e6 && in[i ^ j]) {
                ++sol;
            }
        }
    }
    if (sol % 2 == 0) {
        cout << "Karen" << "\n";
    } else {
        cout << "Koyomi" << "\n";
    }
    return 0;
}