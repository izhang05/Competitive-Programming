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
const long double eps = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) { // [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}

auto t = chrono::steady_clock::now().time_since_epoch().count();


void test_case() {
    cout << fixed << setprecision(18);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < n; ++i) {
        if (a[i] == x && b[i] == y) {
            cout << "Yes" << "\n";
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    cout << 1 << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << "\n";
            return;
        }
    }
    int ga = -1, gb = -1, la = -1, lb = -1;
    long double gaper = -1, gbper = -1, laper = -1, lbper = -1;

    while (chrono::steady_clock::now().time_since_epoch().count() - t < 900000000) {
        int ca = rnd(0, n - 1), cb = rnd(0, n - 1);
        if (ca == cb) {
            continue;
        }
        if (a[ca] > b[cb]) {
            swap(ca, cb);
        }
        if (a[ca] <= x && a[cb] >= x) {
            long double b_per = ((long double) (x - a[ca])) / (a[cb] - a[ca]), a_per = 1 - b_per;
            long double sweet = a_per * b[ca] + b_per * b[cb];
//            cout << ca << " " << cb << " " << a[ca] << " " << a[cb] << " " << a_per << " " << b_per << " " << sweet << "\n";
            if (abs(sweet - y) < eps) {
                cout << "Yes" << "\n";
                for (int i = 0; i < n; ++i) {
                    if (i == ca) {
                        cout << a_per << " ";
                    } else if (i == cb) {
                        cout << b_per << " ";
                    } else {
                        cout << 0 << " ";
                    }
                }
                cout << "\n";
                return;
            }
            if (sweet > y) {
                ga = ca, gb = cb, gaper = a_per, gbper = b_per;
                if (la != -1) {
                    cout << "Yes" << "\n";
                    long double other_sweet = laper * b[la] + lbper * b[lb];
                    long double cur_per = ((long double) (y - other_sweet)) / (sweet - other_sweet), other_per =
                            1 - cur_per;
                    vector<long double> sol(n, 0);
                    sol[ga] += gaper * cur_per;
                    sol[gb] += gbper * cur_per;
                    sol[la] += laper * other_per;
                    sol[lb] += lbper * other_per;

                    for (auto &i: sol) {
                        assert(i >= 0);
                        assert(i <= 1);
                        cout << i << " ";
                    }
                    cout << "\n";
                    return;
                }
            } else {
                la = ca, lb = cb, laper = a_per, lbper = b_per;
                if (ga != -1) {
                    cout << "Yes" << "\n";
                    long double other_sweet = gaper * b[ga] + gbper * b[gb];
                    long double cur_per = ((long double) (y - other_sweet)) / (sweet - other_sweet), other_per =
                            1 - cur_per;
                    vector<long double> sol(n, 0);
                    sol[ga] = gaper * other_per;
                    sol[gb] = gbper * other_per;
                    sol[la] = laper * cur_per;
                    sol[lb] = lbper * cur_per;
                    for (auto &i: sol) {
                        assert(i >= 0);
                        assert(i <= 1);
                        cout << i << " ";
                    }
                    cout << "\n";
                    return;
                }
            }
        }
    }
    cout << "No" << "\n";
}

int main() {
    setIO("1");
    rng.seed(696942000);
    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
