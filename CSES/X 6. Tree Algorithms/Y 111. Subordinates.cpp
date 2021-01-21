#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 2e5;
int sol[maxn];
vector<int> child[maxn];

void dfs(int n) {
    for (int i : child[n]) {
        dfs(i);
        sol[n] += sol[i] + 1;
    }
}

int main() {
    setIO();
    int n, a;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a;
        child[a - 1].push_back(i + 1);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " ";
    }
    return 0;
}
