#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();

    int n, k;
    cin >> n >> k;
    set<int> nums;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        nums.insert(a);
    }
    for (int i = 0; i < k; ++i) {
        cin >> a;
        if (nums.find(a) != nums.end()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
