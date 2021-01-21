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
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int s, n;
        cin >> s >> n;
        int sol = 0;
        if (s % 2 == 1) {
            ++sol;
            --s;
        }
        while (s != 0) {


            if (n % 2 == 0) {
                int num = s % min(n, s);
                sol += s / min(n, s);
                s = num;
            } else {
                int num = s % min(n - 1, s);
                sol += s / min(n - 1, s);
                s = num;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
