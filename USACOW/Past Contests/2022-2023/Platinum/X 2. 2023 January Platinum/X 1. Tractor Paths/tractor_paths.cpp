#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL
#include <debug.h>
#endif

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
const int mxn = 2e5 + 5, mxs = 19;

bool is_s[mxn];
int nxt[mxn], up[mxn][mxs], n;
vector<int> s, adj[mxn];

void build() {
    for (int i = 1; i < mxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}

int solve(int a, int b) {
    if (a == b) {
        return 0;
    }
    int res = 1;
    bool found = true;
    while (found) {
        found = false;
        for (int i = mxs - 1; i >= 0; --i) {
            if (up[a][i] != -1 && up[a][i] < b) {
                a = up[a][i];
                res += 1 << i;
                found = true;
                break;
            }
        }
    }
    return res;
}

int main() {
    setIO("1");
    int q;
    cin >> n >> q;
    string tmp;
    cin >> tmp;
    int l = 0, r = 0;
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < 2 * n; ++i) {
        if (tmp[i] == 'L') {
            ++l;
        } else {
            nxt[r++] = l - 1;
        }
    }
    cin >> tmp;
    for (int i = 0; i < n; ++i) {
        is_s[i] = tmp[i] - '0';
        if (is_s[i]) {
            s.push_back(i);
        }
        up[i][0] = nxt[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << i << " " << nxt[i] << "\n";
    }
    build();
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int cur = solve(a, b);
        cout << cur << " ";
        int spec = 0;
        for (auto &j : s) {
            if (j < a || j > b) {
                continue;
            }
            if (solve(a, j) + solve(j, b) == cur) {
                ++spec;
            }
        }
        cout << spec << "\n";
    }
    return 0;
}
