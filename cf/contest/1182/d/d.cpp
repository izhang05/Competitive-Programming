/* Author: izhang05
 * Time: 12-28-2021 01:10:22
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const long long m1 = 1e9 + 9, p = 9973;

long long pw[maxn]; // Stores the powers of p modulo m1

void calc_pow() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pw[i] = (pw[i - 1] * p) % m1;
    }
}

int down[maxn], up[maxn];
map<int, int> cnt[maxn];
vector<int> adj[maxn];
int dfs1(int c, int par) {
    for (auto &i : adj[c]) {
        if (i != par) {
            ++cnt[c][dfs1(i, c)];
        }
    }
    if (cnt[c].empty()) {
        down[c] = (int) adj[c].size();
    } else if (cnt[c].size() == 1 && cnt[c].begin()->first != -1) {
        down[c] = ((cnt[c].begin()->first * p) % m1 + (int) adj[c].size()) % m1;
    } else {
        down[c] = -1;
    }
    return down[c];
}

void dfs2(int c, int par) {
    if (par != -1) {
        map<int, int> cur = cnt[par];
        if (--cur[down[c]] == 0) {
            cur.erase(down[c]);
        }
        if (par != 0) {
            ++cur[up[par]];
        }
        if (cur.empty()) {
            up[c] = int(adj[par].size());
            if (cnt[c].empty()) {
                cout << c + 1 << "\n";
                exit(0);
            }
            if (cnt[c].size() == 1 && cnt[c].begin()->first == up[c]) {
                cout << c + 1 << "\n";
                exit(0);
            }
        } else if (cur.size() == 1 && cur.begin()->first != -1) {
            up[c] = ((cur.begin()->first * p) % m1 + (int) adj[par].size()) % m1;
            if (cnt[c].empty()) {
                cout << c + 1 << "\n";
                exit(0);
            }
            if (cnt[c].size() == 1 && cnt[c].begin()->first == up[c]) {
                cout << c + 1 << "\n";
                exit(0);
            }
        } else {
            up[c] = -1;
        }
    }
    for (auto &i : adj[c]) {
        if (i != par) {
            dfs2(i, c);
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, -1);
    if (down[0] != -1) {
        cout << 1 << "\n";
        return;
    }
    dfs2(0, -1);
    cout << -1 << "\n";
}

int main() {
    calc_pow();
    setIO("1");
    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
