#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int left = 0, right = 0;
    map<int, int> cur;
    vector<int> sol{0, 0, 0};
    while (right < n) {
        if (cur.find(a[right]) == cur.end()) {
            cur[a[right]] = 1;
            while (cur.size() > k) {
                if (--cur[a[left]] == 0) {
                    cur.erase(a[left]);
                }
                ++left;
            }
        } else {
            ++cur[a[right]];
        }
        if (right - left + 1 > sol[0]) {
            sol[0] = right - left + 1;
            sol[1] = left + 1;
            sol[2] = right + 1;
        }
        ++right;
    }
    cout << sol[1] << " " << sol[2] << "\n";
    return 0;
}