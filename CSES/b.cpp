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
    setIO("b");

    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    vector<int> sol;
    for (int i = 0; i <= 3; ++i) {
        sol.clear();
        sol.push_back(i);
        bool pos = true;
        int last = i;
        for (int j = 0; j < n - 1; ++j) {
            vector<int> ne;
            for (int k = 0; k <= 3; ++k) {
                if (((last | k) == a[j]) && ((last & k) == b[j])) {
                    ne.push_back(k);
                }
            }
            assert(ne.size() <= 1);
            if (ne.empty()) {
#ifdef DEBUG
                cout << "Bad: " << i << "\n";
                print(sol);
#endif
                pos = false;
                break;
            }
            sol.push_back(ne[0]);
            last = ne[0];
        }
        if (pos) {
            cout << "YES"
                 << "\n";
            print(sol);
            return 0;
        }
    }
    cout << "NO"
         << "\n";
    return 0;
}
