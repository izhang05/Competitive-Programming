/* Author: izhang
 * Time: 05-28-2023 20:31:40
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

void q1(int x) {
    cout << "+ " << x << endl;
    int a;
    cin >> a;
    if (a == -2) {
        exit(0);
    }
}

int q2(int x, int y) {
    cout << "? " << x + 1 << " " << y + 1 << endl;
    int res;
    cin >> res;
    if (res == -2) {
        exit(0);
    }
    return res;
}

void guess(const vector<int> &x) {
    cout << "!";
    for (auto &i : x) {
        cout << " " << i;
    }
    cout << endl;
    int a;
    cin >> a;
    if (a == -2) {
        exit(0);
    }
}

void test_case() {
    int n;
    cin >> n;
    q1(n);
    q1(n + 1);
    vector<int> order(n);
    int mn = 0;
    order[0] = 0;
    order[1] = q2(0, 1);
    for (int i = 2; i < n; ++i) {
        int a = q2(i - 1, i), b = q2(i - 2, i);
        if (abs(order[i - 1] + a - order[i - 2]) == b) {
            order[i] = order[i - 1] + a;
        } else {
            order[i] = order[i - 1] - a;
        }
        mn = min(mn, order[i]);
    }
    dbg() << order;
    for (auto &i : order) {
        i -= mn;
    }
    dbg() << order;
    vector<int> line(n);
    line[0] = n;
    for (int i = 1; i < n; i += 2) {
        line[i] = i / 2 + 1;
        if (i + 1 < n) {
            line[i + 1] = n - line[i];
        }
    }
    vector<int> sol;
    sol.reserve(2 * order.size());
    for (auto &i : order) {
        sol.push_back(line[i]);
    }
    reverse(line.begin(), line.end());
    for (auto &i : order) {
        sol.push_back(line[i]);
    }
    guess(sol);
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
