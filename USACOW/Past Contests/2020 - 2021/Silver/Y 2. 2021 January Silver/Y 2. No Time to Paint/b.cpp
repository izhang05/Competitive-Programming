#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'A';
    }
    vector<int> pre(n + 1), rev_pre(n + 1);
    stack<int> seen;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        while (!seen.empty() && seen.top() > a[i]) {
            seen.pop();
        }
        if (!seen.empty() && seen.top() == a[i]) {
        } else {
            ++cur;
        }
        seen.push(a[i]);
        pre[i + 1] = cur;
    }
    while (!seen.empty()) {
        seen.pop();
    }
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (!seen.empty() && seen.top() > a[i]) {
            seen.pop();
        }
        if (!seen.empty() && seen.top() == a[i]) {
        } else {
            ++cur;
        }
        seen.push(a[i]);
        rev_pre[i] = cur;
    }
    int b, c;
    for (int i = 0; i < q; ++i) {
        cin >> b >> c;
        cout << pre[b - 1] + rev_pre[c] << "\n";
    }
    return 0;
}
