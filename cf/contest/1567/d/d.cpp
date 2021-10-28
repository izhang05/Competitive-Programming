/* Author: izhang05
 * Time: 09-29-2021 14:04:27
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

long long p(long long x) {
    long long res = 1;
    for (int i = 0; i < x; ++i) {
        res *= 10;
    }
    return res;
}

void solve() {
    int s, n;
    cin >> s >> n;
    multiset<long long> sol;
    long long mult = 1;
    while (s) {
        if (int(sol.size()) + 1 == n) {
            sol.insert(s * mult);
            break;
        }
        if (s % 10) {
            sol.insert((s % 10) * mult);
        }
        s /= 10;
        mult *= 10;
    }
    while (int(sol.size()) < n) {
        vector<long long> d;
        bool found = false;
        for (auto i : sol) {
            if (i != 1) {
                long long k = 0, orig = i;
                while (i) {
                    i /= 10;
                    ++k;
                }
                --k;
                if (orig - p(k)) {
                    sol.insert(p(k));
                    sol.insert(orig - p(k));
                    sol.erase(sol.find(orig));
                    found = true;
                    break;
                } else if (d.empty()) {
                    d = vector<long long>{p(k - 1), orig - p(k - 1), orig};
                }
            }
        }
        if (!found) {
            sol.insert(d[0]);
            sol.insert(d[1]);
            sol.erase(sol.find(d[2]));
        }
    }
    print(sol);
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
