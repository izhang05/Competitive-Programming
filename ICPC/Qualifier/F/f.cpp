/* Author: izhang
 * Time: 10-19-2025 11:58:45
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
    int n;
    cin >> n;
    if (n == 0) {
        exit(0);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int g;
    cin >> g;
    int orig_g = g;
    for (int i = 0;; ++i) {
        g = orig_g;
        bool pos = true;
        int cur = 50 * i;
        priority_queue<int> exc;
        for (int j = 0; j < n; ++j) {
            if (a[j] > cur) {
                pos = false;
                break;
            }
            exc.push(cur - a[j]);
        }
        if (!pos) {
            continue;
        }
        while (g > 0 && (int) exc.size() >= 3) {
            int x = exc.top();
            exc.pop();
            int y = exc.top();
            exc.pop();
            int z = exc.top();
            exc.pop();
            if (z == 0) {
                break;
            }
            exc.push(x - 1);
            exc.push(y - 1);
            exc.push(z - 1);
            --g;
        }
        if (g == 0) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    setIO("1");

    while (true) {
        test_case();
    }
    return 0;
}
