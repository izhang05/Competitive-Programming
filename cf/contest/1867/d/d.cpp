/* Author: izhang
 * Time: 10-27-2023 14:22:32
**/
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), vis(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            if (b[i] != i) {
                cout << "NO"
                     << "\n";
                return;
            }
        }
        cout << "YES"
             << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        int cur = i;
        vector<int> seen;
        while (!vis[cur]) {
            seen.push_back(cur);
            vis[cur] = true;
            cur = b[cur];
        }
        bool found = false;
        int cnt = 0;
        dbg() << i << " " << seen;
        while (!seen.empty()) {
            ++cnt;
            if (seen.back() == cur) {
                found = true;
                break;
            }
            seen.pop_back();
        }
        if (found && cnt != k) {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
