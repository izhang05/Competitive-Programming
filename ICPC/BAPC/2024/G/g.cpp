#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long tot = 0;
    map<int, int> occ;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int beg = 0;
        for (char j: s) {
            if (j == '.') {
                break;
            }
            beg *= 10;
            beg += j - '0';
        }
        int rem = 10 * (s[int(s.size()) - 2] - '0') + (s[int(s.size()) - 1] - '0');
        tot += 100 * beg + rem;
        ++occ[rem % 5];
    }
    tot -= 2 * (occ[2] + min(occ[3], occ[4])) + occ[1];
    if (occ[3] < occ[4]) {
        tot -= 2 * ((occ[4] - occ[3]) / 3);
    } else {
        tot -= (occ[3] - occ[4]) / 2;
    }
//    cout << tot / 100 << "." << tot % 100 << "\n";
    cout << fixed << setprecision(2) << (long double) tot / 100 << "\n";
}