#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    set<int> indexes;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > n - k) {
            indexes.insert(i);
        }
    }
    cout << (long long ) (n * (n + 1)) / 2 - ((n - k) * (n - k + 1)) / 2 << " ";
    long long sol = 1;
    int pre = *indexes.begin();
    indexes.erase(indexes.begin());
    for (int i : indexes) {
        sol *= (i - pre);
        sol %= mod;
        pre = i;
    }
    cout << sol << "\n";
    return 0;
}
