/* Author: izhang05
 * Time: 07-26-2021 15:55:18
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 30;
int x[maxn * maxs][2], t = 1, cnt[maxn * maxs];

void build(long long s) {
    int v = 0;
    for (long long i = maxs - 1; i >= 0; --i) {
        bool cur = s & (1ll << i);
        if (x[v][cur] == -1) {
            v = x[v][cur] = t++;
        } else {
            v = x[v][cur];
        }
        ++cnt[v];
    }
}

void remove(long long s) {
    int v = 0;
    for (long long i = maxs - 1; i >= 0; --i) {
        bool cur = s & (1ll << i);
        v = x[v][cur];
        --cnt[v];
    }
}

int main() {
    setIO("1");
    int q;
    cin >> q;
    memset(x, -1, sizeof(x));
    build(0);
    while (q--) {
        char c;
        int a;
        cin >> c >> a;
        if (c == '+') {
            build(a);
        } else if (c == '-') {
            remove(a);
        } else {
            int cur = a, v = 0;
            for (int i = maxs - 1; i >= 0; --i) {
                bool goal = !(a & (1 << i));
#ifdef DEBUG
                cout << v << " " << goal << " " << x[v][goal] << " " << i << "\n";
#endif
                if (x[v][goal] != -1 && cnt[x[v][goal]]) {
#ifdef DEBUG
                    cout << v << "\n";
#endif
                    v = x[v][goal];
                    if (goal) {
                        cur ^= (1 << i);
                    }
                } else {
                    v = x[v][!goal];
                    if (!goal) {
                        cur ^= (1 << i);
                    }
                }
            }
            cout << cur << "\n";
        }
    }
    return 0;
}
