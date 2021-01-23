#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        multiset<int> nums;
        for (int j = i; j < n; ++j) {
            cur += a[j];
            nums.insert(a[j]);
            if (cur % (j - i + 1) == 0) {
                int average = cur / (j - i + 1);
                if (nums.find(average) != nums.end()) {
                    ++sol;
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
