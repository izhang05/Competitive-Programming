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

vector<int> a, occ, add;

int sol = 1, n;


void reset(int cur) {
    if (a[cur] + 1 < n) {
        if (occ[a[cur]] > occ[a[cur] + 1]) {
            if (add[a[cur] + 1]) {
                --sol;
                add[a[cur] + 1] = 0;
            }
        }
    }
    if (a[cur] > 0) {
        if (occ[a[cur] - 1] > occ[a[cur]]) {
            if (add[a[cur]]) {
                --sol;
                add[a[cur]] = 0;
            }
        }
    }
}

void modify(int cur) {
    if (a[cur] + 1 < n) {
        if (occ[a[cur]] > occ[a[cur] + 1]) {
            if (!add[a[cur] + 1]) {
                ++sol;
                add[a[cur] + 1] = 1;
            }
        }
    }
    if (a[cur] > 0) {
        if (occ[a[cur] - 1] > occ[a[cur]]) {
            if (!add[a[cur]]) {
                ++sol;
                add[a[cur]] = 1;
            }
        }
    }
}

int main() {
    setIO("12");
    int m;
    cin >> n >> m;
    a.resize(n);
    occ.resize(n);
    add.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        occ[a[i]] = i;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (occ[i + 1] < occ[i]) {
            ++sol;
            ++add[i + 1];
        }
    }
    for (int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        reset(b);
        reset(c);
#ifdef DEBUG
        cout << sol << "\n";
#endif
        swap(occ[a[b]], occ[a[c]]);
        swap(a[b], a[c]);
        modify(b);
        modify(c);
        cout << sol << "\n";
#ifdef DEBUG
        cout << "\n";
#endif
    }
    return 0;
}
