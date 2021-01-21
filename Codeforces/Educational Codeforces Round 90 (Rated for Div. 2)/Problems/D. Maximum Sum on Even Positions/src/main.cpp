#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> even_pre(2, 0);
        vector<int> odd_pre(2, 0);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        even_pre[1] = a[0];
        odd_pre[1] = a[1];
        for (int i = 2; i < n; i += 2) {
            even_pre.push_back(a[i] + even_pre[even_pre.size() - 1]);
        }
        for (int i = 3; i < n; i += 2) {
            odd_pre.push_back(a[i] + odd_pre[odd_pre.size() - 1]);
        }
        int to_add = 0;
        for (int i = 1; i < odd_pre.size(); ++i) {
            to_add = max(to_add, )
        }
    }
    return 0;
}
