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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const string letters = "ACDEHIJKMORST";

void test_case() {
    int n;
    cin >> n;
    vector<set<int>> adj(n);
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        --l[i];
    }
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        --r[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if ((l[i] == j || r[i] == j) && (l[j] == k || r[j] == k)) {
                    adj[i].insert(j);
                    adj[i].insert(k);

                    adj[j].insert(i);
                    adj[j].insert(k);

                    adj[k].insert(i);
                    adj[k].insert(j);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (adj[i].find(i) != adj[i].end()) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    vector<set<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 13; ++j) {
            pos[i].insert(j);
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = *pos[i].begin();
        pos[i].clear();
        pos[i] = {cur};
        for (auto &j : adj[i]) {
            pos[j].erase(cur);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << letters[*pos[i].begin()];
    }
    cout << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        dbg() << imie(i);
        cout << "Case #" << i << ": ";
        test_case();
    }
}
