#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif

    int low = 1, high = 1e6, mid, sol;
    string result;
    while (low <= high) {
        mid = (low + high) / 2;
        cout << mid << endl;
        cin >> result;
        if (result == "<") {
            high = mid - 1;
        } else {
            low = mid + 1;
            sol = mid;
        }
    }
    cout << "! " << sol << endl;
    return 0;
}
