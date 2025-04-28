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

long double dist(long double x1, long double y1, long double x2, long double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

const long double eps = 1e-7;
long double x_1, y_1, x_2, y_2, a;

long double sum_dist(long double x, long double y) {
    return dist(x, y, x_1, y_1) + dist(x, y, x_2, y_2);
}

bool valid_x(long double x) {
    long double lo = -2000, hi = 2000, mid;
    while (hi - lo >= 1e-12) {
        mid = (lo + hi) / 2;
//        cout << "hi" << "\n";
        if (sum_dist(x, mid) <= a) {
//            cout << x << " " << mid << " " << sum_dist(x, mid) << "\n";
            return false;
        }
        if (sum_dist(x, mid) > sum_dist(x, mid + eps)) {
            // move upwards
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return true;
}

bool valid_y(long double y) {
    long double lo = -2000, hi = 2000, mid;
    while (hi - lo >= 1e-12) {
        mid = (lo + hi) / 2;
//        cout << "hi" << "\n";
        if (sum_dist(mid, y) <= a) {
//            cout << x << " " << mid << " " << sum_dist(x, mid) << "\n";
            return false;
        }
        if (sum_dist(mid, y) > sum_dist(mid + eps, y)) {
            // move upwards
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return true;
}


void test_case() {
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> a;
//    if (x_1 == x_2 && y_1 == y_2) {
//        cout << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << "\n";
//        return;
//    }
    if (x_1 > x_2) {
        swap(x_1, x_2);
        swap(y_1, y_2);
    }
    long double lo = -2000, hi = x_1, mid, x_lo;
    while (hi - lo >= 1e-12) {
        mid = (lo + hi) / 2;
        if (valid_x(mid)) {
            x_lo = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }
    lo = x_2, hi = 2000;
    long double x_hi;
    while (hi - lo >= 1e-12) {
        mid = (lo + hi) / 2;
        if (valid_x(mid)) {
            x_hi = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (y_1 > y_2) {
        swap(x_1, x_2);
        swap(y_1, y_2);
    }

    lo = -2000, hi = y_1;
    long double y_lo;
    while (hi - lo >= 1e-12) {
        mid = (lo + hi) / 2;
        if (valid_y(mid)) {
            y_lo = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    lo = y_2, hi = 2000;
    long double y_hi;
    while (hi - lo >= 1e-12) {
        mid = (lo + hi) / 2;
        if (valid_y(mid)) {
            y_hi = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(16) << x_lo << " " << y_lo << " " << x_hi << " " << y_hi << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
