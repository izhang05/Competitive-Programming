/* Author: izhang05
 * Time: 10-22-2021 22:59:12
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int g_and(int i, int j) {
    cout << "AND " << i << " " << j << endl;
    int res;
    cin >> res;
    assert(res != -1);
    return res;
}
int g_or(int i, int j) {
    cout << "OR " << i << " " << j << endl;
    int res;
    cin >> res;
    assert(res != -1);
    return res;
}
int g_xor(int i, int j) {
    cout << "XOR " << i << " " << j << endl;
    int res;
    cin >> res;
    assert(res != -1);
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> sol(n), x(n);
    map<int, int> pre;
    int a = -1;
    bool found = false;
    for (int i = 1; i < n; ++i) {
        x[i] = g_xor(1, i + 1);
        if (!found && (pre.find(x[i]) != pre.end())) {
            int c_1 = x[i] + 2 * g_and(1, i + 1), c_2 = 2 * g_and(pre[x[i]] + 1, i + 1);
            a = (2 * c_1 - c_2) / 2;
            found = true;
        }
        if (!found && x[i] == 0) {
            a = g_and(1, i + 1);
            found = true;
        }
        pre[x[i]] = i;
    }
    if (a == -1) {
        // x is permutation of integers [1, n - 1]
        for (int i = 1; i < n && a == -1; ++i) {
            for (int j = i + 1; j < n && a == -1; ++j) {
                if ((x[i] ^ x[j]) == n - 1) {
                    int c_1 = x[i] + 2 * g_and(1, i + 1), c_2 = x[i] ^ x[j], c_3 = x[j] + 2 * g_and(1, j + 1);
                    a = (c_1 - c_2 + c_3) / 2;
                }
            }
        }
    }
    cout << "! " << a;
    for (int i = 1; i < n; ++i) {
        cout << " " << (x[i] ^ a);
    }
    cout << "\n";
}

int main() {
    setIO();
    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
