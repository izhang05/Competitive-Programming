#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

[[maybe_unused]] const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    map<int, int> cnt;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (++cnt[c] == 3) {
            bad = true;
        } else if (cnt[c] == 2) {
            a.push_back(c);
        } else {
            b.push_back(c);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    if (bad || (!a.empty() && !b.empty() && a.back() == b[0])) {
        cout << -1 << "\n";
        return;
    }
    for (auto &i : a) {
        cout << i << " ";
    }
    for (auto &i : b) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
