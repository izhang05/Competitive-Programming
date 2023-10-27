/* Author: izhang
 * Time: 10-23-2023 19:05:01
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int zero = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == 0) {
            zero = i;
            a[i] = a[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] == 0) {
            zero = i;
            a[i] = a[i + 1];
        }
    }
    if (a[0] == 0) {
        cout << "YES"
             << "\n";
        for (int i = 0; i < n; ++i) {
            cout << q << " ";
        }
        cout << "\n";
        return;
    }
    vector<int> last(q + 1), first(q + 1, inf);
    for (int i = 0; i < n; ++i) {
        last[a[i]] = i;
        first[a[i]] = min(first[a[i]], i);
    }
    vector<vector<int>> add(n), rem(n);
    if (first[q] == inf) {
        if (zero == -1) {
            cout << "NO"
                 << "\n";
            return;
        } else {
            a[zero] = q;
            first[q] = last[q] = zero;
        }
    }
    for (int i = 1; i <= q; ++i) {
        if (first[i] != inf) {
            add[first[i]].push_back(i);
            rem[last[i]].push_back(i);
        }
    }
    set<int> cur;
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        for (auto &j : add[i]) {
            cur.insert(j);
        }
        sol[i] = *cur.rbegin();
        for (auto &j : rem[i]) {
            cur.erase(j);
        }
    }

    //    stack<int> cur;
    //    for (int i = 0; i < n; ++i) {
    //        if (cur.empty()) {
    //            if (i != last[a[i]]) {
    //                cur.push(a[i]);
    //            }
    //        } else {
    //            if (cur.top() > a[i]) {
    //                cout << "NO"
    //                     << "\n";
    //                return;
    //            } else if (cur.top() == a[i]) {
    //                if (i == last[a[i]]) {
    //                    cur.pop();
    //                }
    //            } else {
    //                if (i != last[a[i]]) {
    //                    cur.push(a[i]);
    //                }
    //            }
    //        }
    //    }
    if (sol != a) {
        cout << "NO"
             << "\n";
        return;
    }
    cout << "YES"
         << "\n";
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
