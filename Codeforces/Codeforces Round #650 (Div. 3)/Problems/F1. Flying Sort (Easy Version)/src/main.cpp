#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> a_sort(n);
        a_sort = a;
        sort(a_sort.begin(), a_sort.end());
        if (a_sort == a) {
            cout << 0 << "\n";
        } else {

        }
    }
    return 0;
}