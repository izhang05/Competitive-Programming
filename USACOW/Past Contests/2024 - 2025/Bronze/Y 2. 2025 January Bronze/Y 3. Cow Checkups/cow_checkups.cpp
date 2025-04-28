#include<bits/stdc++.h>

using namespace std;

const int mxa = 1e6 + 5;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + int(a[i - 1] == b[i - 1]);
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + int(a[i] == b[i]);
    }
    vector<int> sol(n + 1);
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int l = i, r = i; l >= 0 && r < n; --l, ++r) {
            cur += int(b[r] == a[l]);
            if (l != r) {
                cur += int(b[l] == a[r]);
            }
            ++sol[cur + pre[l] + suf[r + 1]];
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int l = i, r = i + 1; l >= 0 && r < n; --l, ++r) {
            cur += int(b[r] == a[l]) + int(b[l] == a[r]);
            ++sol[cur + pre[l] + suf[r + 1]];
        }
    }

    for (int i = 0; i <= n; ++i) {
        cout << sol[i] << "\n";
    }
}