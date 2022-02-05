#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    vector<string> a(3), b(3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> b[i];
    }
    int correct = 0, yellow = 0;
    map<char, int> cnt_a, cnt_b;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a[i][j] == b[i][j]) {
                ++correct;
            } else {
                ++cnt_a[a[i][j]];
                ++cnt_b[b[i][j]];
            }
        }
    }
    cout << correct << "\n";
    for (auto &i : cnt_b) {
        yellow += min(i.second, cnt_a[i.first]);
    }
    cout << yellow << "\n";
    return 0;
}
