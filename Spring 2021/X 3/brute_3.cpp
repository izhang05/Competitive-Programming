#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("3");

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    pair<long long, pair<vector<long long>, vector<long long>>> best;
    best.first = inf;
    for (int i = 0; i < (1 << n); ++i) {
        vector<long long> b, c;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                b.push_back(a[j]);
            } else {
                c.push_back(a[j]);
            }
        }
        long long b_sum = 0, c_sum = 0;
        for (auto &j : b) {
            b_sum += j;
        }
        for (auto &j : c) {
            c_sum += j;
        }

        best = min(best, {abs(b_sum - c_sum), {b, c}});
    }
    cout << best.first << "\n";
    print(best.second.first);
    print(best.second.second);

    long long b_sum = 0, c_sum = 0;
    vector<long long> b, c;
    for (int i = 0; i < n; ++i) {
        if (b_sum < c_sum) {
            b_sum += a[i];
            b.push_back(a[i]);
        } else {
            c_sum += a[i];
            c.push_back(a[i]);
        }
    }
    cout << "\n";
    cout << abs(b_sum - c_sum) << "\n";
    print(b);
    print(c);


    return 0;
}
