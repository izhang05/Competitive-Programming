/* Author: izhang
 * Time: 12-22-2025 01:27:50
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

void first() {
    int n;
    cin >> n;
    vector<int> a(n);
    int l, r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            l = i;
        }
        if (a[i] == n) {
            r = i;
        }
    }
    cout << (l < r) << "\n";
}

int ask(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int res;
    cin >> res;
    return res;
}

void second() {
    int n, x;
    cin >> n >> x;
    int lo = 0, hi = n - 1, mid, right;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (ask(0, mid) == n - 1) {
            right = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    lo = 0, hi = n - 1;
    int left;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (ask(mid, n - 1) == n - 1) {
            left = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (x) {
        cout << "! " << right + 1 << endl;
    } else {
        cout << "! " << left + 1 << endl;
    }
}


int main() {
    setIO("1");

    string s;
    cin >> s;
    bool f = s == "first";

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        if (f) {
            first();
        } else {
            second();
        }
    }
    return 0;
}
