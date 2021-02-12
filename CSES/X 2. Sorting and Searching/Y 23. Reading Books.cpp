#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n;
    cin >> n;
    int a;
    priority_queue<long long> nums;
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        s += a;
        nums.push(a);
    }
    cout << max(s, 2 * nums.top()) << "\n";
    return 0;
}
