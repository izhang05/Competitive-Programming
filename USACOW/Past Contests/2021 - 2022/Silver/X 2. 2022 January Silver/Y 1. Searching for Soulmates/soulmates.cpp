#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<long long> vals;
long long b;

long long solve(long long a) {
    long long sol = 0, x = b;
    while (a != x) {
        auto it = lower_bound(vals.begin(), vals.end(), a);
        sol += *it - a;
        a = *it;
        if (a != x) {
            a *= 2;
            ++sol;
        }
    }
    return sol;
}

void test_case() {
    long long a;
    cin >> a >> b;
    vals.clear();
    long long cur = b;
    while (cur) {
        vals.push_back(cur);
        cur /= 2;
    }
    vals.push_back(0);
    reverse(vals.begin(), vals.end());

    cur = 0;
    while (a > b) {
        if (a % 2 == 0) {
            a /= 2;
        } else {
            ++a;
        }
        ++cur;
    }
    long long sol = cur + solve(a);
    while (a > 1) {
        if (a % 2 == 0) {
            a /= 2;
            ++cur;
        } else {
            ++a;
            a /= 2;
            cur += 2;
        }
        sol = min(sol, cur + solve(a));
    }
    cout << sol << "\n";
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
