/*
ID: izhang01
TASK: walk
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
}

//const long long mod = 2019201997, x = 2019201913, y = 2019201949;
//const int maxn = 7505;
//int parent[maxn], comps;
//bool visited[maxn];

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    cout << 2019201997 - 48 * n - 84 * (k - 1) << "\n";
    //    vector<long long> weights(n - 1);
    //    int node = 1;
    //    visited[1] = true;
    //    for (int i = 0; i < n - 1; ++i) {
    //        pair<long long, int> cur = {INT_MAX, 0};
    //        for (int j = 1; j < n + 1; ++j) {
    //            if (!visited[j]) {
    //                cur = min(cur, make_pair((node * x + j * y) % mod, j));
    //            }
    //        }
    //        weights[i] = cur.first;
    //        node = cur.second;
    //        visited[node] = true;
    //    }
    //    sort(weights.begin(), weights.end());
    //    for (int i = 0; i < n - 1; ++i) {
    //        cout << weights[i] << "\n";
    //    }
    //    cout << weights[n - 1 - k] << "\n";
    return 0;
}
