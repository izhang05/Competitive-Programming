/* Author: izhang05
 * Time: 12-30-2021 16:14:46
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1 << 10;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
unordered_set<int> adj[maxn];
vector<vector<int>> blocks;
int cnt = 0;
bool ask(int c) {
    cout << "? " << c + 1 << endl;
    char res;
    cin >> res;
    if (res == 'E') {
        exit(0);
    }
    return res != 'Y';
}
void reset() {
    cout << "R" << endl;
}
void ans(int d) {
    cout << "! " << d << endl;
}
bool pos[maxn];
unordered_set<int> visited;
void dfs(int c) {
    if (adj[c].empty()) {
        return;
    }
    int i = *adj[c].begin();
    while (visited.find(i) != visited.end()) {
        return;
    }
    visited.insert(i);
    adj[i].erase(c);
    adj[c].erase(i);
    --cnt;
    for (auto &j : blocks[i]) {
        if (pos[j]) {
            pos[j] &= ask(j);
        }
    }
    dfs(i);
}

void test_case() {
    memset(pos, true, sizeof(pos));
    int n, k;
    cin >> n >> k;
    int s = max(1, k / 2), b = n / s;
    for (int i = 0; i < b; ++i) {
        for (int j = i + 1; j < b; ++j) {
            adj[i].insert(j);
            adj[j].insert(i);
            ++cnt;
        }
    }
    blocks.resize(b);
    for (int i = 0; i < b; ++i) {
        blocks[i].resize(s);
        for (int j = 0; j < s; ++j) {
            blocks[i][j] = i * s + j;
        }
    }
    while (cnt) {
        int c = rnd(0, b);
        while (adj[c].empty()) {
            c = rnd(0, b);
        }
        for (auto &i : blocks[c]) {
            if (pos[i]) {
                pos[i] &= ask(i);
            }
        }
        visited.clear();
        visited.insert(c);
        dfs(c);
        reset();
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += pos[i];
    }
    ans(sol);
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
