#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}
const int mxn = 1e5;
long long p[mxn];

int main() {
    setIO();

    for (int i = 2; i < mxn; ++i) {
        if (p[i] == 0) {
            for (int j = i; j < mxn; j += i) {
                p[j] = i;
            }
        }
    }

    for (int i = 2; i < mxn; ++i) {
        if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) {
            cout << i << "\n";
        }
    }
    return 0;
}
