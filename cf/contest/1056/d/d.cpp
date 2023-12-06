/* Author: izhang
 * Time: 12-04-2023 19:13:27
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];
int p[mxn], l[mxn];

int dfs(int c, int par) {
    for (auto &i : adj[c]) {
        if (i != par) {
            l[c] += dfs(i, c);
        }
    }
    if (!l[c]) {
        l[c] = 1;
    }
    return l[c];
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        adj[p[i]].push_back(i);
        adj[i].push_back(p[i]);
    }
    dfs(0, -1);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        ++cnt[l[i]];
    }
    int num = 0, val = 1;
    for (int i = 1; i <= n; ++i) {
        while (num < i) {
            num += cnt[val++];
        }
        cout << val - 1 << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
