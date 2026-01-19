/* Author: izhang
 * Time: 06-15-2025 15:54:26
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

int good(pair<int, int> x, pair<int, int> y, int num) {
    if (x.first > y.first) {
        swap(x, y);
    }
//    cout << x.first << " " << y.first << " " << num << "\n";
    if (x.first + num - 1 >= y.first) {
        return 2;
    }
    int dist = y.first - (x.first + num);
    return dist % num == 0;
//    cout << (dist % num == 0 ? "Yes" : "No") << "\n";
}

void test_case() {
    long long w, h, a, b;
    cin >> w >> h >> a >> b;
    pair<long long, long long> x, y;
    cin >> x.first >> x.second >> y.first >> y.second;
//    if (x.second > y.second) {
//        swap(x, y);
//    }
//    if (x.second + b - 1 < y.second) {
//        cout << "Yes" << "\n";
//        return;
//    }
//    int dist;
//    if (x.first <= y.first) {
//        dist = y.first - (x.first + a);
//    } else {
//        dist = x.first - (y.first + a);
//    }
//    cout << dist << "\n";
    int c = good(x, y, a);
    swap(x.first, x.second);
    swap(y.first, y.second);
    int d = good(x, y, b);
    if (c == 1 || d == 1) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
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
