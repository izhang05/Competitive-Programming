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

map<int, int> factor(int x) {
    map<int, int> cur;
    while (x % 2 == 0) {
        ++cur[2];
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ++cur[i];
            x /= i;
        }
    }
    if (x > 1) {
        ++cur[x];
    }
    return cur;
}

int main() {
    setIO("c");
    int n, k;
    cin >> n >> k;
    map<map<int, int>, int> occ;
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        map<int, int> cur = factor(a);
        map<int, int> comp;
        vector<int> to_erase;
        for (auto &j : cur) {
            j.second %= k;
            if (j.second == 0) {
                to_erase.push_back(j.first);
            } else {
                comp[j.first] = k - j.second;
            }
        }
        for (auto &j : to_erase) {
            cur.erase(j);
        }
        if (occ.find(comp) != occ.end()) {
            sol += occ[comp];
        }
        ++occ[cur];
    }
    cout << sol << "\n";
    return 0;
}