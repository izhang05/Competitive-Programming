// left row 3 duke
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool test_case() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    long long xor_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        xor_sum ^= a[i];
    }
    int b2_ind = -1, b1_ind = -1;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (a[i] == 1 && b[i] == 1) {
            b[i] = 0;
        }
    }
    if (xor_sum == 0) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == 2) {
            if (b2_ind != -1) {
                return false;
            }
            b2_ind = i;
        } else if (b[i] == 1 && a[i] >= 2) {
            if (b1_ind != -1) {
                return false;
            }
            b1_ind = i;
        }
    }
    if (b2_ind != -1) {
        // one with b_i = 2
        if (a[b2_ind] % 2 == 1) {
            return false;
        }
        if (((xor_sum ^ a[b2_ind]) != 0) || b1_ind != -1) {
            return false;
        }
        return true;
    } else if (b1_ind != -1) {
        // one with b_i = 1
        long long rem = a[b1_ind];
        if (rem % 2 == 0) {
            --rem;
        }
        if ((xor_sum ^ a[b1_ind] ^ (a[b1_ind] - rem)) != 0) {
            return false;
        }
        return true;
    } else {
        // no b_i = 1 or 2
        if (xor_sum == 0) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--) {
        cout << (test_case() ? "Alice" : "Bob") << "\n";
    }
}