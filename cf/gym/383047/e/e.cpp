/* Author: izhang
 * Time: 05-21-2022 17:49:53
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

struct poster {
    int x1, y1, x2, y2;
};

void test_case() {
    int n;
    cin >> n;
    vector<poster> a(n);
    vector<vector<int>> cnt(20, vector<int>(20));
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        --a[i].x1, --a[i].y1, --a[i].x2, --a[i].y2;
        for (int j = a[i].x1; j <= a[i].x2; ++j) {
            for (int k = a[i].y1; k <= a[i].y2; ++k) {
                ++cnt[j][k];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int dx = a[i].x2 - a[i].x1, dy = a[i].y2 - a[i].y1;
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 20; ++k) {
                if (j + dx >= 20 || k + dy >= 20) {
                    break;
                }
                vector<vector<int>> cur_cnt(20, vector<int>(20));
                for (int l = 0; l < 20; ++l) {
                    for (int m = 0; m < 20; ++m) {
                        cur_cnt[l][m] = cnt[l][m];
                    }
                }
                for (int l = a[i].x1; l <= a[i].x2; ++l) {
                    for (int m = a[i].y1; m <= a[i].y2; ++m) {
                        --cur_cnt[l][m];
                    }
                }
                for (int l = j; l <= j + dx; ++l) {
                    for (int m = k; m <= k + dy; ++m) {
                        ++cur_cnt[l][m];
                    }
                }
                bool good = true;
                for (int l = 0; l < 20; ++l) {
                    for (int m = 0; m < 20; ++m) {
                        good &= cur_cnt[l][m];
                    }
                }
                if (good) {
                    cout << "Yes"
                         << "\n";
                    return;
                }
            }
        }
    }
    cout << "No"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
