#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();
    int n;
    cin >> n;
    map<int, int> pre;
    for (int i = 0; i < n; ++i) {
        pre[i] = 0;
    }
    pre[0] = 1;
    long long sol = 0, a, cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        a %= n;
        cur = (cur + a) % n;
        if (cur < 0) {
            cur += n;
        }
        sol += pre[cur];
        ++pre[cur];
    }
    cout << sol << "\n";
    return 0;
}
