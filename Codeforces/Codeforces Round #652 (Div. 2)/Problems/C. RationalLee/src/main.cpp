#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> w(k);
        for (int i = 0; i < k; ++i) {
            cin >> w[i];
        }
        sort(w.begin(), w.end());
        long long sol = 0;
        int top_ind = n - 1;
        for (int i = 0; i < k; ++i) {
            if (w[i] == 1) {
                sol += 2 * a[top_ind];
                --top_ind;
            } else if (w[i] == 2) {
                sol += a[top_ind] + a[top_ind - 1];
                top_ind -= 2;
            } else {
                sol += a[top_ind];
                --top_ind;
            }
        }
        int bot_ind = 0;
        for (int i = k - 1; i >= 0; --i) {
            if (w[i] == 1 || w[i] == 2) {
                break;
            }
            sol += a[bot_ind];
            bot_ind += w[i] - 1;
        }
        cout << sol << "\n";
    }
    return 0;
}
