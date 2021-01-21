#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
    freopen("2.in", "r", stdin);
#endif
    vector<int> scores(6);
    int sum = 0, num;
    for (int i = 0; i < 6; ++i) {
        cin >> num;
        sum += num;
        scores[i] = num;
    }
    if (sum % 2 == 1) {
        cout << "NO" << "\n";
        return 0;
    } else {
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                for (int k = j + 1; k < 6; ++k) {
                    if (scores[i] + scores[j] + scores[k] == sum / 2) {
                        cout << "YES" << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << "\n";

    return 0;
}
