#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int maxn = 2e5;
int n;
long long bit[2 * maxn];

void update(int i, long long v) {
    for (; i <= n; i += i & (-i)) {
        bit[i] += v;
    }
}

long long query(int i) {
    long long sum = 0;
    for (; i > 0; i -= i & (-i)) {
        sum += bit[i];
    }
    return sum;
}

int main() {
    setIO();
    int q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 1; i < n + 1; ++i) {
        cin >> x[i];
        update(i, x[i]);
    }
    int a, b, c;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c - x[b]);
            x[b] = c;
        } else {
            cout << query(c) - query(b - 1) << "\n";
        }
    }
    return 0;
}