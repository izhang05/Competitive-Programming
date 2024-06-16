/* Author: izhang
 * Time: 06-01-2024 16:30:01
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    int pre = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            if (pre == -1) {
                b[i] = a[i];
                for (int j = i - 1; j >= 0; --j) {
                    if (b[j + 1] == 1) {
                        b[j] = 2;
                    } else {
                        b[j] = b[j + 1] / 2;
                    }
                }
            } else {
                vector<int> x, y;
                int cur_x = a[pre], cur_y = a[i];
                while (cur_x > 0) {
                    x.push_back(cur_x % 2);
                    cur_x /= 2;
                }
                while (cur_y > 0) {
                    y.push_back(cur_y % 2);
                    cur_y /= 2;
                }
                reverse(x.begin(), x.end());
                reverse(y.begin(), y.end());
                for (int j = pre + 1; j <= i; ++j) {
                    if (x.size() > y.size()) {
                        x.pop_back();
                        b[j] = b[j - 1] / 2;
                    } else {
                        int diff = -1;
                        for (int k = 0; k < (int) min(x.size(), y.size()); ++k) {
                            if (x[k] != y[k]) {
                                diff = k;
                                break;
                            }
                        }
                        if (diff != -1) {
                            x.pop_back();
                            b[j] = b[j - 1] / 2;
                        } else {
                            if (x.size() == y.size()) {
                                b[j] = b[j - 1] * 2;
                                x.push_back(0);
                            } else {
                                b[j] = b[j - 1] * 2 + y[int(x.size())];
                                x.push_back(y[int(x.size())]);
                            }
                        }
                    }
                }
                if (b[i] != a[i]) {
                    cout << -1 << "\n";
                    return;
                }
            }
            pre = i;
        }
    }
    if (pre == -1) {
        for (int i = 0; i < n; ++i) {
            b[i] = 1 + (i % 2);
        }
    } else {
        b[pre] = a[pre];
        for (int i = pre + 1; i < n; ++i) {
            if (b[i - 1] == 1) {
                b[i] = 2;
            } else {
                b[i] = b[i - 1] / 2;
            }
        }
    }
    for (auto &i : b) {
        cout << i << " ";
    }
    cout << "\n";
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
