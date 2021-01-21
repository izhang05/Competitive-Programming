#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000;
vector<int> adj[maxn];
bool pos = true;

void dfs(int n, int parent) {
    int cur = 0;
    for (int i : adj[n]) {
        if (i == parent) {
            continue;
        }
        if (adj[i].size() == 1) {
            ++cur;
        } else {
            dfs(i, n);
            if (!pos) {
                return;
            }
        }
    }
    if (cur < 3) {
        pos = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a;
        --a;
        adj[a].push_back(i + 1);
        adj[i + 1].push_back(a);
    }
    dfs(0, -1);
    if (pos) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}
