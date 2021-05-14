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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

const long long inf = 1e18;

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
        }
        vector<int> b;
        long long sum = 0;
        for (auto &i : cnt) {
            b.push_back(i.second);
            sum += i.second;
        }
        long long sol = sum;
        sort(b.begin(), b.end());
#ifdef DEBUG
        print(b);
#endif
        long long cur = 0;
        for (int i = 0; i < (int) b.size(); ++i) {
            if (i > 0) {
                cur += b[i - 1];
            }
#ifdef DEBUG
            cout << i << " " << sum << " " <<  cur << "\n";
#endif
            sol = min(sol, cur + sum - (int(b.size()) - i) * (b[i]));
            sum -= b[i];
        }
        cout << sol << "\n";
    }
    return 0;
}
