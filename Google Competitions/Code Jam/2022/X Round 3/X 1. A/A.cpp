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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k;
void test_case() {
    while (true) {
        vector<int> a(n), ind(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            ind[a[i]] = i;
        }
        vector<int> color(n, 0);
        int nxt = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == i || color[i]) {
                continue;
            }
            int cur = ind[i];
            color[i] = color[cur] = nxt;
            if (!color[ind[cur]]) {
                int nxt_cur = ind[cur];
                color[nxt_cur] = nxt;
                if (!color[ind[nxt_cur]]) {
                    int nxt_nxt_cur = ind[nxt_cur];
                    color[ind[nxt_cur]] = nxt;
                    if (!color[ind[nxt_nxt_cur]]) {
                        color[ind[nxt_nxt_cur]] = nxt;
                    }
                }
            }
            ++nxt;
        }
        for (int i = 0; i < n; ++i) {
            cout << (color[i] ? color[i] : nxt++) << " ";
            //            dbg() << (color[i] ? color[i] : nxt++) << " \n"[i == n - 1];
        }
        cout << endl;

        int good;
        cin >> good;
        if (good == -1) {
            exit(0);
        } else if (good == 1) {
            break;
        }
    }
}

int main() {
    setIO("1");
    cin >> t >> n >> k;
    for (int i = 1; i <= t; ++i) {
        test_case();
    }
}
