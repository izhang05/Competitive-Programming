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
    setIO("18");
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), [](pair<pair<int, int>, int> left, pair<pair<int, int>, int> right) {
        return left.first.first == right.first.first ? left.first.second > right.first.second : left.first.first <
                                                                                                right.first.first;
    });
    vector<vector<int>> sol(2, vector<int>(n));
    set<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
#ifdef DEBUG
        cout << a[i].first.first << " " << a[i].first.second << " " << a[i].second << "\n";
#endif
        while (!q.empty() && q.begin()->first < a[i].first.first) {
            q.erase(q.begin());
        }

        auto it = q.lower_bound({a[i].first.second, 0});
        if (it != q.end()) {
            sol[1][a[i].second] = 1;
        }
        while (it != q.end()) {
            sol[0][it->second] = 1;
            if (next(it) == q.end()) {
                break;
            }
            it = q.erase(it);
        }
        q.insert({a[i].first.second, a[i].second});
    }

    for (int i = 0; i < 2; ++i) {
        print(sol[i]);
    }
    return 0;
}
