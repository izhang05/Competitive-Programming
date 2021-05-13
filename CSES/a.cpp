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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

int ne[maxn];
bool visited[maxn];
priority_queue<long long> s;

void dfs(int c, int d) {
    if (visited[c]) {
        s.push(d);
        return;
    }
    visited[c] = true;
    dfs(ne[c], d + 1);
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ne[i];
        --ne[i];
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
    long long cur = 0;
    for (int i = 0; i < 2; ++i) {
        if (!s.empty()) {
            cur += s.top();
            s.pop();
        }
    }
    long long sol = cur * cur;
    while (!s.empty()) {
        sol += s.top() * s.top();
        s.pop();
    }
    cout << sol << "\n";
    return 0;
}
