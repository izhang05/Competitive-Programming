/* Author: izhang
 * Time: 06-20-2025 15:42:23
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
    map<long long, long long> main, cnt_x;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++main[x + y];
        ++cnt_x[x];
    }


    long long val_m, x;
    for (auto &i: main) {
        if (i.second % 2 == 1) {
            val_m = i.first;
        }
    }
    for (auto &i: cnt_x) {
        if (i.second % 2 == 1) {
            x = i.first;
        }
    }
    long long y = val_m - x;
    cout << x << " " << y << "\n";
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



///* Author: izhang
// * Time: 06-20-2025 15:42:23
//**/
//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//
//#include <debug.h>
//
//#else
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
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
//
//void test_case() {
//    int n;
//    cin >> n;
//    map<long long, long long> main, off;
//    for (int i = 0; i < n; ++i) {
//        int x, y;
//        cin >> x >> y;
//        ++off[x - y];
//        ++main[x + y];
//    }
//    set<long long> nums;
//    for (auto &i: off) {
//        if (i.second % 2 == 1) {
//            nums.insert(i.first);
//        }
//    }
//    for (auto &i: nums) {
//        cout << i << " ";
//    }
//    cout << "\n";
//    while (nums.size() > 1) {
//        long long cur = *nums.begin();
//        nums.erase(nums.begin());
//        long long nxt = *nums.begin();
//        if ((nxt - cur) % 4 == 0) {
//            nums.erase(nxt);
//            continue;
//        }
//        if (nxt - cur > 4) {
//            nums.insert(nxt - (nxt - cur) % 4);
//            continue;
//        }
////        assert(nums.size() > 1);
//        long long nxt_nxt = *next(nums.begin());
//        if (nxt_nxt - cur < 4) {
//            if (nxt_nxt == cur + 2 && nums.size() >= 3 && *next(next(nums.begin())) == cur + 3) {
//                nums.erase(nums.begin());
//                nums.erase(nums.begin());
//                nums.erase(nums.begin());
//            } else {
//                vector<long long> vals{cur, nxt, *next(nums.begin()), 0};
//                nums.erase(nxt);
//                nums.erase(nums.begin());
//                for (int i = 0; i < 4; ++i) {
//                    if (vals[i] != vals[0] + i) {
//                        nums.insert(vals[0] + i);
//                        break;
//                    }
//                }
//            }
//            continue;
//        }
//        nums.erase(nums.begin());
//        if (nxt == cur + 3) {
//            nums.insert(cur + 1);
//            nums.insert(cur + 2);
//        } else if (nxt == cur + 2) {
//            nums.insert(nxt_nxt - 1);
//            nums.insert(nxt_nxt - 3);
//        } else {
//            if (nxt_nxt % 2 == cur % 2) {
//                nums.insert(nxt_nxt - 2);
//                nums.insert(nxt_nxt - 1);
//            } else {
//                nums.insert(nxt_nxt - 2);
//                nums.insert(nxt_nxt - 3);
//            }
//        }
//    }
//    long long val_o = *nums.begin(), val_m;
//    for (auto &i: main) {
//        if (i.second % 2 == 1) {
//            val_m = i.first;
//        }
//    }
//    cout << val_o << " " << val_m << "\n\n";
//    long long x = (val_o + val_m) / 2, y = val_m - x;
//    cout << x << " " << y << "\n";
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
