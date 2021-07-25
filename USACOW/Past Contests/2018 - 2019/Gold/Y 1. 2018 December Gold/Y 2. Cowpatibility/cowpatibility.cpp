/*
ID: izhang01
TASK: cowpatibility
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
}

//#define DEBUG
map<array<int, 5>, long long> cnt;

int main() {
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> a(5);
        for (int j = 0; j < 5; ++j) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        for (int j = 1; j < (1 << 5); ++j) {
            vector<int> cur;
            for (int k = 0; k < 5; ++k) {
                if (j & (1 << k)) {
                    cur.push_back(a[k]);
                }
            }
            array<int, 5> add{0};
            for (int k = 0; k < int(cur.size()); ++k) {
                add[k] = cur[k];
            }
            ++cnt[add];
        }
    }
    long long sol = ((long long) n * (n - 1)) / 2;
    for (auto &i : cnt) {
        long long cur = (i.second * (i.second - 1)) / 2;
        int num = 0;
        for (int j = 0; j < 5; ++j) {
            if (i.first[j]) {
                ++num;
            }
        }
        if (num % 2 == 0) {
            cur *= -1;
        }
        sol -= cur;
    }

    cout << sol << "\n";
    return 0;
}
