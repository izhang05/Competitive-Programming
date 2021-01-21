#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("solution.out", "w", stdout);
    freopen("3.in", "r", stdin);
#endif
}

long long tri(long long n) {
    return (n * (n + 1)) / 2;
}

int main() {
    setIO();

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n % 4 == 1 || n % 4 == 2) {
            cout << 0 << "\n";
            continue;
        }
        long long goal = tri(n) / 2, low = 0, high = n, mid, sol = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (tri(mid) == goal) {
                sol = n - mid + tri(mid - 1) + tri(n - mid - 1);
                break;
            }
            if (tri(mid) > goal) {
                high = mid - 1;
            } else {
                low = mid + 1;
                sol = n - mid;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
