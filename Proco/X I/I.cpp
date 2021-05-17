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
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    long long avg = sum / n;
    vector<pair<int, int>> b;
    int last = 0;
    bool zero = true;
    for (int i = 0; i < n; ++i) {
        int cur = a[i] - avg;
        if (cur == 0) {
            if (zero) {
                ++last;
            } else {
                b.emplace_back(last, 0);
                last = 1;
            }
            zero = true;
        } else {
            if (!zero) {
                last += cur;
            } else {
                b.emplace_back(0, last);
                last = cur;
            }
            zero = false;
        }
    }
    if (zero) {
        b.emplace_back(0, last);
    } else {
        b.emplace_back(last, 0);
    }
#ifdef DEBUG
    for (auto &i : b) {
        cout << i.first << " " << i.second << "\n";
    }
#endif
    return 0;
}
