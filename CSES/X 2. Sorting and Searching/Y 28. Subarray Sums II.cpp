#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();
    int n, x;
    cin >> n >> x;
    map<long long, int> pre;
    pre[0] = 1;
    long long sol = 0, a, cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        cur += a;
        if (pre.find(cur - x) != pre.end()) {
            sol += pre[cur - x];
        }
        if (pre.find(cur) == pre.end()) {
            pre[cur] = 1;
        } else {
            ++pre[cur];
        }
    }
    cout << sol << "\n";
    return 0;
}
