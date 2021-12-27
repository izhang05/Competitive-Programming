/* Author: izhang05
 * Time: 12-27-2021 16:41:36
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
    vector<int> a(n, -1), q(n, -1);
    q[0] = ask(0, 1, 2);
    for (int i = 3; i < n; i += 3) {
        q[i] = ask(i, i + 1, i + 2);
    }
    int zero, one;
    pair<int, int> diff;
    for (int i = 3; i < n; i += 3) {
        if (q[i] != q[i - 3]) {
            diff = {i - 3, i};
            for (int j = i - 2; j <= i; ++j) {
                if (q[j] == -1) {
                    q[j] = ask(j, j + 1, j + 2);
                }
                if (q[j] != q[j - 1]) {
                    zero = j - 1, one = j + 2;
                    if (q[j] < q[j - 1]) {
                        swap(zero, one);
                    }
                    a[zero] = 0, a[one] = 1;
                    break;
                }
            }
            for (int j = i - 3; j < i + 3; ++j) {
                if (j != zero && j != one) {
                    a[j] = ask(j, zero, one);
                }
            }
            break;
        }
    }
    for (int i = 0; i < n; i += 3) {
        if (i == diff.first || i == diff.second) {
            continue;
        }
        if (q[i] == 0) {
            if (ask(i, i + 1, one) == 0) {
                a[i] = a[i + 1] = 0;
                a[i + 2] = ask(i + 2, zero, one);
            } else {
                a[i + 2] = 0;
                a[i] = ask(i, zero, one);
                a[i + 1] = 1 ^ a[i] ^ a[i + 2];
            }
        } else {
            if (ask(i, i + 1, zero) == 1) {
                a[i] = a[i + 1] = 1;
                a[i + 2] = ask(i + 2, zero, one);
            } else {
                a[i + 2] = 1;
                a[i] = ask(i, zero, one);
                a[i + 1] = a[i] ^ a[i + 2];
            }
        }
    }

    vector<int> sol;
    for (int i = 0; i < n; ++i) {
        if (!a[i]) {
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
