#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int main() {
    setIO("8");

    int n, x;
    cin >> n >> x;
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i + 1;
    }
    int sol = 0;
    do {
        int mx = n + 1, mn = -1;
        bool pre = false;
        int cur = 0;
        for (auto &i : perm) {
            if (i > x) {
                if (i < mx) {
                    mx = i;
                    pre = true;
                }
            } else {
                if (i > mn) {
                    mn = i;
                    if (pre) {
                        ++cur;
                    }
                    pre = false;
                }
            }
        }
        sol += cur;
        if (cur) {
            for (auto &i : perm) {
                cout << i << " ";
            }
            cout << cur << "\n";
        }

    } while (next_permutation(perm.begin(), perm.end()));
    cout << sol << "\n";
    return 0;
}
