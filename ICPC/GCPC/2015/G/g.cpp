#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b)

int main() {
    int n;
    cin >> n;
    int res = 9001;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            res = min(res, a[j] - a[i]);
        }
    }
    cout << (res >= 0 ? "yes" : "no") << "\n";
}