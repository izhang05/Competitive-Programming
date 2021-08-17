/* Author: izhang05
 * Time: 08-16-2021 22:16:06
**/
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
vector<int> s;

vector<int> prefix_function() {
    int n = (int) s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
void solve() {
    int n, w;
    cin >> n >> w;
    if (w == 1) {
        cout << n << "\n";
        return;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(w);
    for (int i = 0; i < w; ++i) {
        cin >> b[i];
    }
    int pre = b[0];
    for (int i = 1; i < w; ++i) {
        s.push_back(b[i] - pre);
        pre = b[i];
    }
    s.push_back('#');
    pre = a[0];
    for (int i = 1; i < n; ++i) {
        s.push_back(a[i] - pre);
        pre = a[i];
    }
    vector<int> kmp = prefix_function();
    int sol = 0;
    for (int i = w + 1; i < int(kmp.size()); ++i) {
        if (kmp[i] == w - 1) {
            ++sol;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
