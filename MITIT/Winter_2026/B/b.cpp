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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<long long, long long>> a;
int n;

bool pos(long long x) {
    long long mx = -INFL;
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (a[i].first - a[j].first > x) {
            mx = max(mx, a[j].second);
            ++j;
        }
        if (a[i].second + x < mx) {
            return false;
        }
    }
    return true;
}

void test_case() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    long long lo = 0, hi = 1e17, mid, sol = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (pos(mid)) {
            hi = mid - 1;
            sol = mid;
        } else {
            lo = mid + 1;
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




//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//#include <debug.h>
//#else
//
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
//
//#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#endif
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//vector<pair<long long, long long>> a;
//int n;
//
//bool pos(long long x) {
//    long long pre = -INFL, mn = INFL, mx = -INFL;
//    for (int i = 0; i < n; ++i) {
//        if (pre == -INFL) {
//            pre = a[i].first;
//        } else {
//            if (a[i].first - pre <= x) {
//                mn = min(mn, a[i].second);
//                mx = max(mx, a[i].second);
//            } else {
//
//            }
//        }
//    }
//}
//
//void test_case() {
//    cin >> n;
//    a.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i].first >> a[i].second;
//    }
//    sort(a.begin(), a.end());
//    long long lo = 0, hi = 1e17, mid, sol;
//    while (lo <= hi) {
//        mid = (lo + hi) / 2;
//        if (pos(mid)) {
//            hi = mid - 1;
//            sol = mid;
//        } else {
//            lo = mid + 1;
//        }
//    }
//    cout << sol << "\n";
//}
//
//int main() {
//    setIO("1");
//
//    int test_case_number = 1;
//    cin >> test_case_number;
//    while (test_case_number--) {
//        test_case();
//    }
//    return 0;
//}
