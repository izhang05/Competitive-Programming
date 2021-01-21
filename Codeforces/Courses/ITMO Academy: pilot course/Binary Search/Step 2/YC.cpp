#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int n, x, y;

bool pos(long long cur) {
    return (cur - min(x, y)) / x + (cur - min(x, y)) / y + 1 >= n;
}

int main() {
    setIO();

    cin >> n >> x >> y;
    long long l = min(x, y), r = 2e9 + 1, mid, sol;
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
