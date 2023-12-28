#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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


int main() {
    setIO("1");
    int n;
    cin >> n;
    string s;
    cin >> s;
    int days = 1e9, pre = -1;
    vector<int> intervals;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (pre != -1) {
                intervals.push_back(i - pre);
                if (pre == 0) {
                    days = min(days, i - pre - 1);
                } else {
                    days = min(days, (i - pre - 1) / 2);
                }
            }
            pre = -1;
        } else if (pre == -1) {
            pre = i;
        }
    }
    if (pre != -1) {
        intervals.push_back(n - pre);
        days = min(days, n - pre - 1);
    }
    if (days == 1e9) {
        cout << 0 << "\n";
        return 0;
    }
    int sol = 0;
    for (auto &i : intervals) {
        sol += (i + 2 * days) / (2 * days + 1);
    }
    cout << sol << "\n";
    return 0;
}
