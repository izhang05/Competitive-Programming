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

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: Lukas Polacek
     * Date: 2009-10-26
     * License: CC0
     * Source: folklore
     * Description: Disjoint-set data structure.
     * Time: $O(\alpha(N))$
     */

    struct UF {
        vi e;
        UF(int n) : e(n, -1) {}
        bool sameSet(int a, int b) { return find(a) == find(b); }
        int size(int x) { return -e[find(x)]; }
        int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
        bool join(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (e[a] > e[b]) swap(a, b);
            e[a] += e[b];
            e[b] = a;
            return true;
        }
    };

} // namespace kactl
//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct interval {
    int l, r, a;
};

void test_case() {
    int n;
    cin >> n;
    vector<interval> l(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edges;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> events;
    for (auto &i : l) {
        cin >> i.l >> i.r >> i.a;
    }
    for (int i = 0; i < n; ++i) {
        events.emplace(l[i].l, -(i + 1));
        events.emplace(l[i].r, i + 1);
    }
    multiset<pair<int, int>> seen{{l[-events.top().second - 1].a, -events.top().second - 1}};
    events.pop();
    while (!events.empty()) {
        pair<int, int> cur = events.top();
        dbg() << cur;
        events.pop();
        if (cur.second < 0) {
            cur.second *= -1;
            --cur.second;
            if (seen.empty()) {
                cout << -1 << "\n";
                return;
            }
            auto it = seen.lower_bound({l[cur.second].a, -1});
            if (it != seen.end()) {
                edges.push({it->first - l[cur.second].a, {cur.second, it->second}});
            }
            it = seen.lower_bound({l[cur.second].a, n + 1});
            if (it != seen.begin()) {
                it = prev(it);
                edges.push({l[cur.second].a - it->first, {cur.second, it->second}});
            }
            seen.insert({l[cur.second].a, cur.second});
        } else {
            --cur.second;
            seen.erase(seen.find({l[cur.second].a, cur.second}));
        }
    }
    long long sol = 0;
    kactl::UF dsu(n);
    while (!edges.empty()) {
        pair<int, pair<int, int>> cur = edges.top();
        edges.pop();
        if (dsu.join(cur.second.first, cur.second.second)) {
            sol += cur.first;
        }
    }
    cout << sol << "\n";
    dbg();
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
