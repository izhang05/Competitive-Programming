/* Author: izhang05
 * Time: 07-20-2021 21:07:36
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
map<int, int> cnt[maxn];
int a[maxn], bad[maxn], cnt_a[maxn];
bool down[maxn], up[maxn];
vector<int> adj[maxn];
map<int, int> total_cnt;

void dfs(int c, int p) {
    down[c] = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            down[c] &= down[i];
            if (!down[i]) {
                ++bad[c];
            }
            if (cnt[i].size() > cnt[c].size()) {
                swap(cnt[i], cnt[c]);
            }
            for (auto &j : cnt[i]) {
                cnt[c][j.first] += j.second;
            }
            cnt[i].clear();
        }
    }
    if (cnt[c][a[c]]) {
        down[c] = false;
    }
    cnt_a[c] = cnt[c][a[c]];
    ++cnt[c][a[c]];
}

void dfs2(int c, int p) {
    cnt[c].clear();
    up[c] = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
            if (cnt[i].size() > cnt[c].size()) {
                swap(cnt[i], cnt[c]);
            }
            for (auto &j : cnt[i]) {
                cnt[c][j.first] += j.second;
            }
            cnt[i].clear();
        }
    }
    ++cnt[c][a[c]];
    if (cnt[c][a[c]] != total_cnt[a[c]]) {
        up[c] = false;
    }
    if (p != -1) {
        up[c] &= up[p];
        if (cnt_a[p] - cnt[c][a[p]]) {
            up[c] = false;
        }
        int cur_bad = bad[p];
        if (!down[c]) {
            --cur_bad;
        }
        if (cur_bad) {
            up[c] = false;
        }
    }
}

void dfs3(int c, int p) {
    if (p != -1) {
        up[c] &= up[p];
#ifdef DEBUG
        cout << c << " " << p << " " << up[c] << " " << up[p] << "\n";
#endif
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs3(i, c);
        }
    }
}

int main() {
    setIO("3");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++total_cnt[a[i]];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    dfs3(0, -1);
    int sol = 0;
    for (int i = 0; i < n; ++i) {
#ifdef DEBUG
        cout << i << " " << down[i] << " " << up[i] << "\n";
#endif
        if (down[i] && up[i]) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
