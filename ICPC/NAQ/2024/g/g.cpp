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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            for (int k = 0; k < 3; ++k) {
//                for (int l = 0; l < 3; ++l) {
//                    for (int m = 0; m < 3; ++m) {
//                        for (int i1 = 0; i1 < 3; ++i1) {
//                            long double cur = (i - 1) * log(a[0].second);
//                            cur += (j - 1) * log(a[1].second);
//                            cur += (k - 1) * log(a[2].second);
//                            cur += (l - 1) * log(a[3].second);
//                            cur += (m - 1) * log(a[4].second);
//                            cur += (i1 - 1) * log(a[5].second);
//                            if (cur>2.97&&cur<2.971) {
//                                cout << i << " " << j << " " << k << " " << l << " " << m << " " << i1 << "\n";
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }


    map<int, vector<long double>> nums;
    for (int i = 0; i < n; ++i) {
        int s, c;
        cin >> s >> c;
        nums[s].push_back(c);
    }
    long double sol = 0;
    for (auto &i: nums) {
        sort(i.second.begin(), i.second.end());
        int m = (int) i.second.size();
        for (int j = 0; j < m - j - 1; ++j) {
            sol += log(i.second[m - j - 1]) - log(i.second[j]);
        }
    }
    cout << fixed << setprecision(16) << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
