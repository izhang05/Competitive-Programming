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
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string sol;
    int cnt = 0, last_h = -inf, last_g = -inf, cur_g = inf, cur_h = inf;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            if (i - last_g > k && cur_g == inf) {
                cur_g = i;
            }
        } else {
            if (i - last_h > k && cur_h == inf) {
                cur_h = i;
            }
        }
        if (i == n - 1) {
            if (cur_g == inf && cur_h == inf) {
                sol.push_back('.');
            } else if (cur_g == inf && cur_h != inf) {
                sol.push_back('H');
                ++cnt;
            } else if (cur_g != inf && cur_h == inf) {
                sol.push_back('G');
                ++cnt;
            } else if (cur_g != inf && cur_h != inf) {
                for (int j = (int) sol.size() - 1; j >= 0; --j) {
                    if (sol[j] == '.') {
                        sol.erase(j, 1);
                        break;
                    }
                }
                sol.push_back('G');
                sol.push_back('H');
                cnt += 2;
            }
        } else if (i - cur_g == k) {
            sol.push_back('G');
            ++cnt;
            cur_g = inf;
            last_g = i;
        } else if (i - cur_h == k) {
            sol.push_back('H');
            ++cnt;
            cur_h = inf;
            last_h = i;
        } else {
            sol.push_back('.');
        }
    }
    cout << cnt << "\n";
    cout << sol << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
