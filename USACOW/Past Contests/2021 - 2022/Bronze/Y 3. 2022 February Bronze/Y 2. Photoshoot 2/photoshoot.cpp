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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

// fenwick tree in bronze lol :yaw: but I don't see any other solution :notlikeduck:
long long s[maxn];
int n;
void update(int pos, long long add) {
    for (; pos < n; pos |= pos + 1) {
        s[pos] += add;
    }
}
long long query(int pos) {
    long long res = 0;
    for (; pos > 0; pos &= pos - 1) {
        res += s[pos - 1];
    }
    return res;
}


void test_case() {
    cin >> n;
    vector<int> a(n), ind(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ind[a[i]] = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    int sol = 0, added = 0;
    for (int i = 0; i < n; ++i) {
        dbg() << ind[b[i]] + added + query(ind[b[i]]) << i;
        if (ind[b[i]] + added + query(ind[b[i]]) != i) {
            update(ind[b[i]], -1);
            ++sol, ++added;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
