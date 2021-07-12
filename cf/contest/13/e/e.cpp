/* Author: izhang05
 * Time: 07-12-2021 14:17:55
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
int n, k;

int block(int x) {
    return x / k;
}

vector<int> a, nex, cnt;

void calc(int b) {
    for (int i = min(n - 1, (b + 1) * k - 1); i >= b * k; --i) {
        int next = i + a[i];
#ifdef DEBUG
        cout << i << " " << a[i] << " " << next << "\n";
#endif
        if (next >= n) {
            nex[i] = n;
            cnt[i] = 1;
        } else if (block(next) != b) {
            nex[i] = next;
            cnt[i] = 1;
        } else {
            if (nex[next] != n) {
                nex[i] = nex[next];
                cnt[i] = cnt[next] + 1;
            } else {
                nex[i] = next;
                cnt[i] = 1;
            }
        }
    }
}

int main() {
    setIO("2");

    int m;
    cin >> n >> m;
    a.resize(n), nex.resize(n), cnt.resize(n);
    k = int(sqrt(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i * k < n; ++i) {
        calc(i);
    }
    while (m--) {
        int t, v;
        cin >> t >> v;
        --v;
        if (t == 0) {
            int b;
            cin >> b;
            a[v] = b;
            calc(block(v));
        } else {
            int sol = 0, cur = v;
#ifdef DEBUG
            cout << cur << " " << nex[cur] << " " << cnt[cur] << "\n";
#endif
            while (nex[cur] != n) {
#ifdef DEBUG
                cout << cur << " " << nex[cur] << " " << cnt[cur] << "\n";
#endif
                sol += cnt[cur];
                cur = nex[cur];
            }
            sol += cnt[cur];
            cout << cur + 1 << " " << sol << "\n";
        }
    }
    return 0;
}
