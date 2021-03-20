#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
//#define DEBUG

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    int maxn = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    vector<long long> pre(maxn + 1);
    for (int i = 0; i < n; ++i) {
        ++pre[a[i]];
    }
    for (int i = 0; i < maxn; ++i) {
        pre[i + 1] += pre[i];
    }
#ifdef DEBUG
    cout << "maxn:"
         << " " << maxn << "\n";
    cout << "pre: "
         << "\n";
    print(pre);
#endif
    long long sol = 0;
    for (int x = 1; x <= maxn; ++x) {
#ifdef DEBUG
        cout << x << ":"
             << "\n";
#endif
        map<int, int> odds;
        for (int t = 1; t * x <= maxn; ++t) {
            int cur = pre[min(maxn, (t + 1) * x - 1)] - pre[t * x - 1];
            if (cur % 2 == 1) {
                odds[t] = cur;
            }
        }
#ifdef DEBUG
        for (auto i : odds) {
            cout << i.first << " " << i.second << "\n";
        }
        cout << "\n";
#endif
        if (odds.size() > 2) {
            continue;
        }
        if (odds.size() == 1) {
            if (odds.begin()->first == 1) {
                sol += odds.begin()->second;
            }
        } else if (odds.size() == 2) {
            if (odds.begin()->first + 1 == next(odds.begin())->first) {
                sol += next(odds.begin())->second;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
