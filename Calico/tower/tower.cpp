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
    vector<long long> p(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i + n] = p[i];
    }
    vector<long long> d(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    vector<long long> pre(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) {
        pre[i + 1] = pre[i] + d[i];
    }

    deque<int> blocked;
    long long sol = 0;
    for (int i = n; i < 2 * n; ++i) {
        if (sol < p[i]) {
            blocked.push_back(i);
        }
        sol = max(sol, p[i]);
        if (i != 2 * n - 1) {
            sol += d[i];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        long long t = p[i];
        int cur = i;
        while (!blocked.empty()) {
            int nxt = blocked.front();
            long long nxt_t = t + pre[nxt] - pre[cur];
            if (nxt_t >= p[nxt]) {
                cur = nxt;
                t = nxt_t;
                blocked.pop_front();
            } else {
                break;
            }
        }
        blocked.push_front(i);
        int ind = blocked.back();
        t = p[ind] + pre[i + n - 1] - pre[ind];
        sol = min(sol, t);
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
//    vector<long long> p(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> p[i];
//    }
//    vector<long long> d(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> d[i];
//    }
//    long long sol = INFL;
//    for (int i = 0; i < n + 1; ++i) {
//        long long t = 0;
//        for (int j = 0; j < n; ++j) {
//            t = max(t, p[j]);
//            if (j != n - 1) {
//                t += d[j];
//            }
//        }
//        sol = min(sol, t);
//        rotate(p.begin(), p.end() - 1, p.end());
//        rotate(d.begin(), d.end() - 1, d.end());
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
