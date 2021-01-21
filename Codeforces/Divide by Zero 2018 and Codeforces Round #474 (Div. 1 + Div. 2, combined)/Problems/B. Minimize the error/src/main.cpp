#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k1, k2, k;
    cin >> n >> k1 >> k2;
    k = k1 + k2;
    priority_queue<int> different;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        different.push(abs(a[i] - b[i]));
    }
    for (int i = 0; i < k; ++i) {
        int cur = different.top();
        different.pop();
        if (cur > 0) {
            different.push(cur - 1);
        } else {
            different.push(cur + 1);
        }
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += pow(different.top(), 2);
        different.pop();
    }
    cout << sol << "\n";
    return 0;
}
