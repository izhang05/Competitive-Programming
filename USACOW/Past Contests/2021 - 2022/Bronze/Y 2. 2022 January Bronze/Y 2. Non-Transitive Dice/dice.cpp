#include <bits/stdc++.h>

using namespace std;

bool beats(const vector<int> &a, const vector<int> &b) {
    int total = 0, good = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (a[i] > b[j]) {
                ++total;
                ++good;
            } else if (a[i] < b[j]) {
                ++total;
            }
        }
    }
    return good * 2 > total;
}
void solve() {
    vector<int> a(4), b(4);
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (beats(b, a)) {
        swap(a, b);
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            for (int k = 1; k <= 10; ++k) {
                for (int l = 1; l <= 10; ++l) {
                    vector<int> c{i, j, k, l};
                    if (beats(b, c) && beats(c, a)) {
                        cout << "yes"
                             << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "no"
         << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
