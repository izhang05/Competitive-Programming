
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


int main() {
    int t;
    setIO();
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long sol = 0;
        long long pre;
        cin >> pre;
        long long s;
        for (long long i = 0; i < n - 1; ++i) {
            cin >> s;
            sol += abs(s - pre) - 1;
            pre = s;
        }
        cout << sol << "\n";
    }
    return 0;
}
