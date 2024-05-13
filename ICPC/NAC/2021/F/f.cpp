#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    vector<int> a;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = -1;
    for (int i = 0; i < n; ++i) {
        int cur = -1;
        for (int l = 1; i - l >= 0 && i + l < n; ++l) {
            if (a[i - l] == a[i + l] && (a[i - l] < a[i - l + 1])) {
                cur = 1 + 2 * l;
            } else {
                break;
            }
        }
        sol = max(sol, cur);
    }
    cout << sol << "\n";
}