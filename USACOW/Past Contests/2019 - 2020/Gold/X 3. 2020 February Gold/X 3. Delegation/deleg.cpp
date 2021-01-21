/*
ID: izhang01
TASK: deleg
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
}
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int dp[maxn], k;
bool sol;
bitset<maxn> solution;


void dfs(int node, int p) {
    multiset<int> children;
    for (int i : adj[node]) {
        if (i != p) {
            dfs(i, node);
            if (!sol) {
                return;
            }
            children.insert(dp[i]);
        }
    }
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it + 1 == k) {
            children.erase(it);
            continue;
        }
        auto it2 = children.find(k - *it - 2);
        if (it2 != children.end()) {
            if (it2 == it) {
                if (next(it2) != children.end() && *next(it2) == *it2) {
                    it2 = next(it2);
                } else {
                    continue;
                }
            }
            children.erase(it2);
            children.erase(it);
            continue;
        }
    }
    if (children.size() == 1) {
        dp[node] = *children.begin() + 1;
    } else if (children.size() > 1) {
        sol = false;
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (k = 1; k < n; ++k) {
        if ((n - 1) % k != 0) {
            solution[k - 1] = false;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        sol = true;
        dfs(0, -1);
        solution[k - 1] = sol;
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << solution[i];
    }
    return 0;
}
