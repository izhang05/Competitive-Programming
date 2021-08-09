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
const long long INFL = 0x3f3f3f3f3f3f3f3f;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
int n, k, sol;
void gen(vector<int> a) {
    if (a.size() == n) {
        int and_s = a[0];
        for (int i = 1; i < n; ++i) {
            and_s &= a[i];
        }
        int xor_s = a[0];
        for (int i = 1; i < n; ++i) {
            xor_s ^= a[i];
        }
        if (and_s >= xor_s) {
//            print(a);
            ++sol;
        }
        return;
    }
    for (int i = 0; i < (1 << k); ++i) {
        a.push_back(i);
        gen(a);
        a.pop_back();
    }
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        sol = 0;
        cin >> n >> k;
        gen(vector<int>());
        cout << sol << "\n";
    }
    return 0;
}
