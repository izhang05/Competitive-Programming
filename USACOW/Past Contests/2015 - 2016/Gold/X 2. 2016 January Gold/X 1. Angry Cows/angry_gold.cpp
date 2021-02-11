/*
ID: izhang01
TASK: angry
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
}
//#define DEBUG
const int maxn = 5e4 + 5;
int l[maxn], r[maxn];

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    int n;
    int sol = 1e9;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
#endif
    for (int i = 1; i < n; ++i) {
        l[i] = max(l[i - 1] + 2, a[i] - a[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        r[i] = max(r[i + 1] + 2, a[i + 1] - a[i]);
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << l[i] << " " << r[i] << "\n";
    }
    cout << "\n";
#endif
    int i = 0, j = n - 1;
    while (i < j) {
        sol = min(sol, max((a[j] - a[i]) / 2, 2 + max(l[i], r[j])));
        if (l[i + 1] <= r[j - 1]) {
            ++i;
        } else {
            --j;
        }
    }
    if (a.empty()) {
    }
    cout << fixed << setprecision(1) << double(sol) / 2 << "\n";
#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(18) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
