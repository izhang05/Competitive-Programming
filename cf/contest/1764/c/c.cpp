/* Author: izhang
 * Time: 12-05-2022 15:16:27
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
    string f_in = "in" + name + ".txt";
    ifstream f(f_in.c_str());
    if (f.good()) {
        freopen(f_in.c_str(), "r", stdin);
    } else {
        freopen(("testI" + name + ".txt").c_str(), "r", stdin);
    }
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<int, int> right, left;
    for (int i = 1; i < n; ++i) {
        ++right[a[i]];
    }
    ++left[a[0]];
    long long sol = 0;
    for (int i = 1; i < n; ++i) {
        dbg() << imie(left);
        dbg() << imie(right);
        long long cur = (long long) i * (n - i);
        long long l = left.rbegin()->second, r = right.begin()->second;
        if (left.rbegin()->first == right.begin()->first) {
            cur -= l * r;
        }
        sol = max(sol, cur);
        ++left[a[i]];
        if (--right[a[i]] == 0) {
            right.erase(a[i]);
        }
    }
    sol = max(sol, (long long) n / 2);
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        dbg() << test_case_number;
        test_case();
    }
    return 0;
}
