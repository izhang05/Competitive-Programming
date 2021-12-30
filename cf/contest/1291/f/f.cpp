/* Author: izhang05
 * Time: 12-30-2021 16:14:46
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1 << 10;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool ask(int c) {
    cout << "? " << c + 1 << endl;
    char res;
    cin >> res;
    if (res == 'E') {
        exit(0);
    }
    return res != 'Y';
}
void reset() {
    cout << "R" << endl;
}
void ans(int d) {
    cout << "! " << d << endl;
}
bool pos[maxn];

void test_case() {
    int n, k;
    cin >> n >> k;
    memset(pos, true, sizeof(pos));
    int s = max(1, k / 2), b = n / s;
    for (int i = 0; i < b; ++i) {
        for (int j = i + 1; j < b; ++j) {
            for (int l = 0; l < s; ++l) {
                int cur = i * s + l;
                pos[cur] &= ask(cur);
            }
            for (int l = 0; l < s; ++l) {
                int cur = j * s + l;
                pos[cur] &= ask(cur);
            }
            reset();
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += pos[i];
    }
    ans(sol);
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
