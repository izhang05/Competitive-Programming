#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long long m1 = 1e9 + 9, p = 9973, m2 = 1e9 + 7;


//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(42069);

long long rnd(long long l, long long r) { // [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}

long long hsh[260], hsh2[260];

long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
//    cin.exceptions(cin.failbit);
    for (int i = 0; i < 260; ++i) {
        hsh[i] = rnd(0, 1e18);
        hsh2[i] = rnd(0, 1e18);
    }
    string s, tmp;
    while (cin >> tmp) {
        s += tmp;
    }
    cin >> s;

    vector<int> a;
    int cur = 0;
    for (char c: s) {
        if (c == ',') {
            a.push_back(cur);
            cur = 0;
        } else {
            cur *= 10;
            cur += c - '0';
        }
    }
    a.push_back(cur);
    int n = int(a.size());
    for (int i = min(n, 256); i >= 64; --i) {
        pair<int, int> sol{1e9, 1e9};
//        map<multiset<int>, int> seen;
        unordered_map<__int128, int> seen;
        unordered_map<__int128, int> seen2;
//        map<int, int> occ;
        __int128 cur_hsh = 0, cur_hsh2 = 0;
        for (int j = 0; j < i; ++j) {
            cur_hsh += hsh[a[j]];
            cur_hsh2 += hsh2[a[j]];
//            range.insert({a[j], j});
        }
        seen[cur_hsh] = 0;
        seen2[cur_hsh2] = 0;
//        long long cur_hsh1 = hsh1(range), cur_hsh2 = hsh2(range);
//        seen[merge(cur_hsh1, cur_hsh2)] = 0;
//        seen[range] = 0;
        for (int j = 1; j + i - 1 < n; ++j) {
            cur_hsh += -hsh[a[j - 1]] + hsh[a[j - 1 + i]];
            cur_hsh2 += -hsh2[a[j - 1]] + hsh2[a[j - 1 + i]];
//            int ind = range.order_of_key(pair<int, int>{a[j - 1], j - 1});
//            cur_hsh1 -= a[j - 1] * pw1[j - ind - 1];
//            cur_hsh1 = (cur_hsh1 + m1) % m1;
//            cur_hsh2 -= a[j - 1] * pw2[j - ind - 1];
//            cur_hsh2 = (cur_hsh2 + m2) % m2;


//            range.erase(range.find(a[j - 1]));
//            range.insert(a[j + i - 1]);
//            __int128 cur_hsh = merge(cur_hsh1, cur_hsh2);
            if (seen.find(cur_hsh) != seen.end()) {
                if (seen[cur_hsh] + i - 1 < j) {
                    sol = min(sol, pair<int, int>(seen[cur_hsh], j));
                }
            } else {
                seen[cur_hsh] = j;
//                seen2[cur_hsh2] = j;
            }
//            if (seen.find(cur_hsh) != seen.end() && seen2.find(cur_hsh2) != seen2.end()) {
//                if (seen2[cur_hsh2] != seen[cur_hsh]) {
//                    seen[cur_hsh] = j;
//                    seen2[cur_hsh2] = j;
//                    assert(false);
//                } else if (seen2[cur_hsh2] == seen[cur_hsh] && seen[cur_hsh] + i - 1 < j) {
//                    sol = min(sol, pair<int, int>(seen[cur_hsh], j));
//                }
//            } else {
//                seen[cur_hsh] = j;
//                seen2[cur_hsh2] = j;
//            }
        }
        if (sol != pair<int, int>(1e9, 1e9)) {
            cout << i << "\n" << sol.first << "\n" << sol.second << "\n";
            return 0;
        }
    }
    cout << "no key\n";
}