/*
ID: izhang01
TASK: threesum
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
}
const int maxn = 5e3 + 1;

unordered_map<int, int> pre[maxn];

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    unordered_map<int, int> cur;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < i; ++j) {
            ++cur[a[j] + a[i]];
        }
        pre[i] = cur;
    }

    return 0;
}
