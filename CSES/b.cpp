#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    freopen("b.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO();

    int n;
    cin >> n;
    set<int> seen;
    seen.insert(0);
    for (int i = 1; i < n + 1; ++i) {
        int a;
        cin >> a;
        auto it = seen.find(a);
        if (it != seen.end()) {
            seen.erase(it);
        }
        seen.insert(i);
    }
    cout << seen.size() << "\n";
    return 0;
}
