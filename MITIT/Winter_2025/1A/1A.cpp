//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//
//#include <debug.h>
//
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
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e5 + 5;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//int good[mxn];
//
//void test_case() {
//    long long n;
//    cin >> n;
//    int sol = 0;
//    good[1] = true;
//    for (int i = 1; i <= n; ++i) {
//        vector<int> cur;
//        int num = i;
//        while (num) {
//            if (num % 10 != 0) {
//                cur.push_back(num % 10);
//            }
//            num /= 10;
//        }
//        for (auto &j: cur) {
//            if (i % j == 0 && good[i / j]) {
//                good[i] = true;
//            }
//        }
//        sol += good[i];
//    }
//    cout << sol << "\n";
//}
//
//int main() {
//    setIO("1");
//
//    int test_case_number = 1;
//    while (test_case_number--) {
//        test_case();
//    }
//    return 0;
//}

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

set<long long> nums;

void test_case() {
    long long n;
    cin >> n;
    queue<long long> q;
    q.push(1);
    nums.insert(1);
    while (!q.empty()) {
        long long cur = q.front();
        q.pop();
        for (int i = 2; i <= 9; ++i) {
            long long nxt = cur * i, nxt_cp = nxt;
            if (nxt > n || nums.find(nxt) != nums.end()) {
                continue;
            }
            while (nxt_cp) {
                if (nxt_cp % 10 == i) {
                    nums.insert(nxt);
                    q.push(nxt);
                    break;
                }
                nxt_cp /= 10;
            }
        }
    }
    cout << nums.size() << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
