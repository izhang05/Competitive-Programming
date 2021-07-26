/* Author: izhang05
 * Time: 07-25-2021 22:48:16
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

int x[maxn][26], t = 1;
vector<int> child[maxn];

void build(const string& s) {
    int v = 0;
    for (auto &i : s) {
        if (x[v][i - 'a'] == -1) {
            child[v].push_back(t);
            v = x[v][i - 'a'] = t++;
        } else {
            v = x[v][i - 'a'];
        }
    }
}
bool win[maxn], lose[maxn];
void dfs(int c) {
    if (child[c].empty()) {
        win[c] = false;
        lose[c] = true;
    }
    for (auto &i : child[c]) {
        dfs(i);
        win[c] |= (!win[i]);
        lose[c] |= (!lose[i]);
    }
}

int main() {
    setIO("1");
    memset(x, -1, sizeof(x));
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        build(s);
    }
    dfs(0);
    if (!win[0]) {
        cout << "Second" << "\n";
    } else {
        if (lose[0]) {
            cout << "First" << "\n";
        } else {
            if (k % 2 == 1) {
                cout << "First" << "\n";
            } else {
                cout << "Second" << "\n";
            }
        }
    }
    return 0;
}
