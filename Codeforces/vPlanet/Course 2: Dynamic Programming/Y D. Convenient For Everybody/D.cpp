#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int s, f;
    cin >> s >> f;
    long long current = 0, zones = f - s;
    for (int i = 0; i < zones; ++i) {
        current += a[i];
    }
    pair<long long, long long> sol = {s, current};
    for (int i = 1; i < n; ++i) {
        current += a[(i + zones - 1) % n] - a[i - 1];
//        cout << i << " " << current << "\n";
        if (current > sol.second) {
            sol.second = current;
            sol.first = (s - i + n) % n;
            if (!sol.first) {
                sol.first = n;
            }
        } else if (current == sol.second) {
            int solution = (s - i + n) % n;
            if (!solution) {
                solution = n;
            }
            if (solution < sol.first) {
                sol.first = solution;
            }
        }
    }
//    cout << sol.first << " " << sol.second << "\n";
    cout << sol.first << "\n";
}
