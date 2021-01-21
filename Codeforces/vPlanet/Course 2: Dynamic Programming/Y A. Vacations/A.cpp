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
    vector<int> days(n);
    for (int i = 0; i < n; ++i) {
        cin >> days[i];
    }
    vector<int> gym(n, 101);
    vector<int> contest(n, 101);
    vector<int> rest(n, 101);
    rest[0] = 1;
    if (days[0] == 1) {
        contest[0] = 0;
    } else if (days[0] == 2) {
        gym[0] = 0;
    } else if (days[0] == 3) {
        gym[0] = 0;
        contest[0] = 0;
    }
    for (int i = 1; i < n; ++i) {
        rest[i] = min({gym[i - 1], contest[i - 1], rest[i - 1]}) + 1;
        if (days[i] == 1) {
            contest[i] = min(gym[i - 1], rest[i - 1]);;
        } else if (days[i] == 2) {
            gym[i] = min(contest[i - 1], rest[i - 1]);
        } else if (days[i] == 3) {
            gym[i] = min(contest[i - 1], rest[i - 1]);
            contest[i] = min(gym[i - 1], rest[i - 1]);
        }
    }
    cout << min({gym[n - 1], contest[n - 1], rest[n - 1]}) << "\n";
    return 0;
}
