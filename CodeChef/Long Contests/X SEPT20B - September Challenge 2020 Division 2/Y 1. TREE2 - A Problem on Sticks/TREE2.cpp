#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("2.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n;
        set<int> nums;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            if (a != 0) {
                nums.insert(a);
            }
        }
        cout << nums.size() << "\n";
    }
    return 0;
}
