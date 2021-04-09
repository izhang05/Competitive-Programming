/*
ID: izhang01
TASK: lamps
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
}
//#define DEBUG

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    int n, c;
    cin >> n >> c;
    vector<int> on, off;
    while (true) {
        int a;
        cin >> a;
        if (a == -1) {
            break;
        }
        --a;
        on.push_back(a);
    }
    while (true) {
        int a;
        cin >> a;
        if (a == -1) {
            break;
        }
        --a;
        off.push_back(a);
    }
#ifdef DEBUG
    for (int i : on) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i : off) {
        cout << i << " ";
    }
    cout << "\n";
#endif
    set<vector<bool>> sols;
    for (int i = 0; i < (1 << 4); ++i) {
        vector<bool> a(n, true);
        int count = 0;
        if (i & (1 << 0)) {
            for (int j = 0; j < n; ++j) {
                a[j] = !a[j];
            }
            ++count;
        }
        if (i & (1 << 1)) {
            for (int j = 0; j < n; j += 2) {
                a[j] = !a[j];
            }
            ++count;
        }
        if (i & (1 << 2)) {
            for (int j = 1; j < n; j += 2) {
                a[j] = !a[j];
            }
            ++count;
        }
        if (i & (1 << 3)) {
            for (int j = 0; j < n; j += 3) {
                a[j] = !a[j];
            }
            ++count;
        }
        bool pos = true;
        if (count <= c && count % 2 == c % 2) {
            for (int j : on) {
                if (!a[j]) {
                    pos = false;
                    break;
                }
            }
            for (int j : off) {
                if (a[j]) {
                    pos = false;
                    break;
                }
            }
            if (pos) {
                sols.insert(a);
            }
        }
    }

    for (const auto &i : sols) {
        for (auto j : i) {
            cout << j;
        }
        cout << "\n";
    }
    if (sols.empty()) {
        cout << "IMPOSSIBLE"
             << "\n";
    }

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
