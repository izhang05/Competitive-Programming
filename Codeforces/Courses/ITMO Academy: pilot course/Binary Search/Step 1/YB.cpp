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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int b;
    for (int i = 0; i < k; ++i) {
        cin >> b;
        int lo = 0, hi = n - 1, mid, sol = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (a[mid] > b) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
                sol = mid;
            }
        }
        cout << sol + 1 << "\n";
    }
    return 0;
}
