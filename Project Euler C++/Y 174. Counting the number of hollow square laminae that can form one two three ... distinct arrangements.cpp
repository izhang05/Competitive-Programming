#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 1e6;
    map<int, int> cnt;
    for (int i = 3; i * i - (i - 2) * (i - 2) <= n; ++i) {
        for (int j = i - 2; i * i - j * j <= n && j >= 1; j -= 2) {
            ++cnt[i * i - j * j];
        }
    }
    int sol = 0;
    for (auto &i: cnt) {
        if (i.second <= 10) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
