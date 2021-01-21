#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long w, h, n;

bool pos(long long cur) {
    unsigned long long x = (cur / w) * (cur / h);
    return x >= n;
}

int main() {
    setIO();
    cin >> w >> h >> n;
    long long l = 0, r = 1e18, mid, sol;
    while (l <= r) {
        mid = (l + r) / 2;
        if (pos(mid)) {
            sol = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}

