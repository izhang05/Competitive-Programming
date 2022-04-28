/* Author: izhang
 * Time: 04-15-2022 23:12:38
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
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = 0;
    for (int i = 0; i <= z; ++i) {
        int end = k - 2 * i;
        if (end < 0) {
            break;
        }
        long long cur = 0;
        priority_queue<int> q;
        for (int j = 0; j <= end; ++j) {
            cur += a[j];
            if (j + 1 < n) {
                for (int l = 0; l < i; ++l) {
                    q.push(a[j] + a[j + 1]);
                }
            }
        }
        int cnt = i;
        while (!q.empty() && cnt--) {
            cur += q.top();
            q.pop();
        }
        sol = max(sol, cur);
    }
    cout << sol << "\n";
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
