/*
ID: izhang01
TASK: reorder
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("reorder.in", "r", stdin);
    freopen("reorder.out", "w", stdout);
}

const int maxn = 100;

vector<int> a, b;
bool visited[maxn];
int sol, longest;

int index(int n) {
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == n) {
            return i;
        }
    }
    assert(false);
}

void start_dfs(int n, int len) {
//    cout << a[n] + 1 << "\n";
    visited[node] = true;
    int next = ind(a[node]);
    if (!visited[next]) {
        start_dfs(next, dist + 1);
    } else {
        longest = max(longest, dist);
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            visited[i] = true;
        }
        if (!visited[i]) {
            start_dfs(i, 1);
//            cout << "\n";
            ++sol;
        }
    }
    if (sol == 0) {
        longest = -1;
    }
    cout << sol << " " << longest << "\n";
    return 0;
}
