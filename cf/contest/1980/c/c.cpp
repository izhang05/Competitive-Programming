/* Author: izhang
 * Time: 06-03-2024 10:35:01
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
    map<int, int> ind;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ind[b[i]] = i;
    }
    int m;
    cin >> m;
    vector<int> d(m);
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
    }
    set<pair<int, int>> events;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            events.insert({b[i], i});
        }
    }
    //    if (events.empty()) {
    //        for (int i = 0; i < m; ++i) {
    //            if (ind.find(d[i]) != ind.end()) {
    //                cout << "YES"
    //                     << "\n";
    //                return;
    //            }
    //        }
    //        cout << "NO"
    //             << "\n";
    //    } else {
    int bad = false;
    for (int i = 0; i < m; ++i) {
        auto it = events.lower_bound({d[i], -1});
        if (it == events.end() || it->first != d[i]) {
            if (ind.find(d[i]) == ind.end()) {
                bad = true;
            } else {
                bad = false;
            }
            //            if (ind.find(d[i]) == ind.end()) {
            //                cout << "NO"
            //                     << "\n";
            //                return;
            //            }
        } else {
            bad = false;
            events.erase(it);
        }
    }
    if (!events.empty() || bad) {
        cout << "NO"
             << "\n";
        return;
    }
    cout << "YES"
         << "\n";
    //    }
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
