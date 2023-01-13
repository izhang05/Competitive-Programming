#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T, typename U>
bool ckmax(T &t, const U &u) {
    return u > t ? t = u, true : false;
}

double query(double x, double y) {
    cout << "P " << x << ' ' << y << '\n';
    double ans;
    cin >> ans;
    return ans;
}

void solve() {
    double a = 5000;
    double r = query(0, 0) / 2;
    double b = query(0, a) / 2 - a;
    double y = (a * a + r * r - b * b) / (2 * a);
    double x = sqrt(r * r - y * y);
    double eps = query(x, y) - 2 * sqrt(x * x + y * y);
    cout << "B " << (eps < 1 ? x : -x) << ' ' << y << '\n';
    string s;
    cin >> s;
}

int main() {
    cout.precision(9);
    // cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();
}