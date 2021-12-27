/* Author: izhang05
 * Time: 12-27-2021 16:21:16
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int ask(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    int res;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
    return res;
}

void ans(const vector<int> &a) {
    cout << "! " << a.size();
    for (auto &i : a) {
        cout << " " << i + 1;
    }
    cout << endl;
}

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n, -1), q(n);
    q[0] = ask(0, 1, 2);
    vector<int> sol;
    pair<int, int> diff;
    for (int i = 1; i < n - 2; ++i) {
        q[i] = ask(i, i + 1, i + 2);
        if (q[i] != q[i - 1]) {
            if (q[i] > q[i - 1]) {
                sol.push_back(i - 1);
            } else {
                sol.push_back(i + 2);
            }
            diff = {i - 1, i + 2};
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i != diff.first && i != diff.second && ask(i, diff.first, diff.second) == 0) {
            sol.push_back(i);
        }
    }
    ans(sol);
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
