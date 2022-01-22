/* Author: izhang
 * Time: 01-22-2022 16:27:58
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 300;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
map<string, int> mem;
int ask(const string &s) {
    if (mem.find(s) != mem.end()) {
        return mem[s];
    }
    cout << s << endl;
    cin >> mem[s];
    if (mem[s] == 0) {
        exit(0);
    }
    return mem[s];
}

void test_case() {
    string s;
    for (int i = 0; i < maxn; ++i) {
        s.push_back('a');
    }
    int a = ask(s);
    for (int i = 0; i < maxn; ++i) {
        s[i] = 'b';
    }
    int b = ask(s);
    int n = 600 - (a + b), cnt_a = b + n - 300, cnt_b = a + n - 300;
    s.clear();
    for (int i = 0; i < n; ++i) {
        s.push_back('a');
    }
    int orig = cnt_b;
    string sol;
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        s[i] = 'b';
        if (ask(s) >= orig) {
            sol.push_back('a');
            ++cnt;
        } else {
            sol.push_back('b');
        }
        s[i] = 'a';
    }
    if (cnt == cnt_a) {
        sol.push_back('b');
    } else {
        sol.push_back('a');
    }
    ask(sol);
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
