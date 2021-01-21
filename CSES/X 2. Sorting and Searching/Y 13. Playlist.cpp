#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0, l = 0;
    set<int> nums;
    for (int r = 0; r < n; ++r) {
        while (nums.find(a[r]) != nums.end()) {
            nums.erase(a[l++]);
        }
        nums.insert(a[r]);
        sol = max(sol, r - l + 1);
    }
    cout << sol << "\n";
    return 0;
}
