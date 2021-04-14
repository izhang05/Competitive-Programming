#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO(string name) {
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
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int s = 1000;
    vector<int> sol;
    int en = s;
#ifdef DEBUG
    for (auto i : a) {
        cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
    }
    cout << "\n";
#endif
    for (int i = 0; i < n; en += s) {
        vector<pair<pair<int, int>, int>> cur;
        while (i < n && a[i].first.first <= en) {
#ifdef DEBUG
            cout << i << " " << a[i].first.first << " " << a[i].first.second << " " << a[i].second << "\n";
#endif
            cur.push_back(a[i]);
            ++i;
        }
        sort(cur.begin(), cur.end(), [](pair<pair<int, int>, int> left, pair<pair<int, int>, int> right) {
            return left.first.second == right.first.second ? left.first.first < right.first.first : left.first.second <
                                                                                                    right.first.second;
        });
        for (auto j : cur) {
//#ifdef DEBUG
//            cout << j.first.first << " " << j.first.second << " " << j.second << "\n";
//#endif
            sol.push_back(j.second);
        }
    }
    print(sol);
    return 0;
}
