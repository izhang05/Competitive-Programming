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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool sol = false;
int n, m;
vector<int> a;

bool sub(vector<int> &cur) {
    int i = 0;
    for (auto &j : cur) {
        if (a[i] == j) {
            ++i;
        }
    }
    return i == n;
}

void gen(vector<int> cur) {
    if (sub(cur)) {
        sol = true;
        return;
    }
    if (cur.size() == a.size()) {
        return;
    }
    vector<int> nex(cur.size() - 1);
    for (int i = 0; i < int(cur.size()); ++i) {
        for (int j = 0; j < i; ++j) {
            nex[j] = cur[j];
        }
        for (int j = i + 1; j < int(cur.size()); ++j) {
            nex[j - 1] = cur[j];
        }
        gen(nex);
    }
    for (int i = 0; i < (int) cur.size() - 1; ++i) {
        for (int j = 0; j < i; ++j) {
            nex[j] = cur[j];
        }
        nex[i] = cur[i] + cur[i + 1];
        for (int j = i + 2; j < int(cur.size()); ++j) {
            nex[j - 1] = cur[j];
        }
        gen(nex);
        if (sol) {
            return;
        }
    }
}

void solve() {
    cin >> n >> m;
    --n;
    a.resize(n);
    int pre;
    cin >> pre;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[i] = b - pre;
        pre = b;
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    if (n > m) {
        cout << "NO" << "\n";
        return;
    }
    if (n == 0) {
        cout << "YES" << "\n";
        return;
    }
    sol = false;
    gen(b);
    cout << (sol ? "YES" : "NO") << "\n";
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
