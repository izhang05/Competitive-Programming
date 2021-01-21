/*
ID: izhang01
TASK: loan
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
}

long long n, k, m;

bool pos(long long x) {
    long long cur = n, y = cur / x, used = 0, next;
    while (y > m) {
        next = x * (y - 1) + x - 1;
        long long used_cur = (cur - next + y - 1) / y; // ceil(cur - next)/y
        used += used_cur;
        cur -= used_cur * y;
        y = cur / x;
    }
    used += (cur + m - 1) / m; // ceil(cur / m)
    return used <= k;
}


int main() {
    setIO();
    cin >> n >> k >> m;
    long long low = 1, high = n, mid, sol;
    while (low <= high) {
        mid = (low + high) / 2;
        if (pos(mid)) {
            sol = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << sol << "\n";
    return 0;
}