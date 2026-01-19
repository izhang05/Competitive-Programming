/* Author: izhang
 * Time: 06-29-2025 16:10:31
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
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a.begin(), a.end());
    map<int, int, greater<>> cnt;
    long long sol = 0, cur = 0;
    ++cnt[a[0] + a[1]];
    int ind = -1;
    for (int i = 2; i < n; ++i) {
        if (a[i] >= mx - a[i]) {
            ind = i;
            break;
        }
        while (!cnt.empty() && cnt.begin()->first > mx - a[i]) {
            cur += cnt.begin()->second;
            cnt.erase(cnt.begin());
        }
        sol += cur;
        for (int j = 0; j < i; ++j) {
            if (a[j] + a[i] > mx - a[i]) {
                ++cur;
            } else {
                ++cnt[a[j] + a[i]];
            }
        }
    }
    map<int, int> cnt2;
    cur = 0;
    for (int i = 0; i < ind; ++i) {
        for (int j = 0; j < i; ++j) {
            ++cnt2[a[i] + a[j]];
            ++cur;
        }
    }
    for (int i = ind; i < n; ++i) {
        while (!cnt2.empty() && cnt2.begin()->first <= a[i]) {
            cur -= cnt2.begin()->second;
            cnt2.erase(cnt2.begin());
        }
        sol += cur;
        for (int j = 0; j < i; ++j) {
            if (a[j] + a[i] > a[i]) {
                ++cnt2[a[j] + a[i]];
                ++cur;
            }
        }
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
