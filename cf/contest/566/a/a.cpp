/* Author: izhang05
 * Time: 07-26-2021 16:57:12
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 8e5 + 5;
int num_a[maxn], num_b[maxn];
vector<int> ind_a[maxn], ind_b[maxn];
struct trie {
    int x[maxn][26]{}, t = 1;
    vector<int> child[maxn];

    void init() {
        memset(x, -1, sizeof(x));
    }
    void build(const string &s, bool a, int ind) {
        int v = 0;
        for (int i = 0; i < int(s.size()); ++i) {
            if (x[v][s[i] - 'a'] == -1) {
                child[v].push_back(t);
                v = x[v][s[i] - 'a'] = t++;
            } else {
                v = x[v][s[i] - 'a'];
            }
            if (i == int(s.size()) - 1) {
                if (a) {
                    ind_a[v].push_back(ind);
                    ++num_a[v];
                } else {
                    ind_b[v].push_back(ind);
                    ++num_b[v];
                }
            }
        }
    }
};

int sol = 0, match[maxn];
trie t;

void dfs(int c, int d) {
    for (auto &i : t.child[c]) {
        dfs(i, d + 1);
        if (ind_a[i].size() > ind_a[c].size()) {
            swap(ind_a[i], ind_a[c]);
        }
        while (!ind_a[i].empty()) {
            ind_a[c].push_back(ind_a[i].back());
            ind_a[i].pop_back();
        }
        if (ind_b[i].size() > ind_b[c].size()) {
            swap(ind_b[i], ind_b[c]);
        }
        while (!ind_b[i].empty()) {
            ind_b[c].push_back(ind_b[i].back());
            ind_b[i].pop_back();
        }
    }
    while (!ind_a[c].empty() && !ind_b[c].empty()) {
        sol += d;
        match[ind_a[c].back()] = ind_b[c].back();
        ind_a[c].pop_back(), ind_b[c].pop_back();
    }
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    t.init();
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        t.build(s, true, i);
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        t.build(s, false, i);
    }
    dfs(0, 0);
    cout << sol << "\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " " << match[i] + 1 << "\n";
    }
    return 0;
}
