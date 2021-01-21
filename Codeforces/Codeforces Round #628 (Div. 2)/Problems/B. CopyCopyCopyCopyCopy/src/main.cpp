#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t, n;
    cin >> t;
    unordered_set<int> nums;
    long long num;
    while (t--) {
        cin >> n;
        nums.clear();
        for (int i = 0; i < n; ++i) {
            cin >> num;
            nums.insert(num);
        }
        cout << nums.size() << "\n";
    }
    return 0;
}