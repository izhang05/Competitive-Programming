#include <bits/stdc++.h>

using namespace std;

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

[[maybe_unused]] const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
map<pair<int, int>, long long> mn, mx;
string s;
int nex[maxn];

pair<long long, long long> dfs(int l, int r) {
    long long cur_mn, cur_mx;
    if (r - l) {
        int nr = nex[l + 1];
        pair<long long, long long> cur = dfs(l + 1, nr);
        cur_mn = cur.first, cur_mx = cur.second;
        cur = dfs(nr + 2, r - 1);
        if (s[nr + 1] == '+') {
            cur_mn += cur.first, cur_mx += cur.second;
        } else {
            cur_mn -= cur.second, cur_mx -= cur.first;
        }
    } else {
        cur_mn = 0, cur_mx = 1;
    }
    return {mn[{l, r}] = cur_mn, mx[{l, r}] = cur_mx};
}


void solve() {
    int q;
    cin >> s >> q;
    int n = int(s.size());
    if (n == 1) {
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << 1 << "\n";
        }
        return;
    }
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        nex[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int cur = st.top();
            st.pop();
            nex[cur] = i;
        }
    }
    mn.clear();
    mx.clear();
    dfs(0, n - 1);

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << mx[{l, r}] << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
