#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long long m1 = 1e9 + 9, p = 9973, m2 = 1e9 + 7;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) { // [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 260;
long long pw1[maxn]; // Stores the powers of p modulo m1
long long pw2[maxn];
int n;
long long hsh[maxn];

void calc_hashes() {
    hsh[0] = 1;
    for (int i = 0; i < n; ++i) {
        hsh[i + 1] = ((hsh[i] * p) % m1 + s[i]) % m1;
    }
}

long long get_hash(int a, int b) { // [a, b]
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % m1 + m1) % m1;
}

void calc_pow() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pw1[i] = (pw1[i - 1] * p) % m1;
        pw2[i] = (pw2[i - 1] * p) % m1;
    }
}

long long hsh1(indexed_set<pair<int, int>> cur) {
    long long cur_hash = 0;
    for (auto i: cur) {
        cur_hash = ((cur_hash * p) % m1 + i.first) % m1;
    }
    return cur_hash;
}

long long hsh2(indexed_set<pair<int, int>> cur) {
    long long cur_hash = 0;
    for (auto i: cur) {
        cur_hash = ((cur_hash * p) % m2 + i.first) % m2;
    }
    return cur_hash;
}

__int128 hsh(indexed_set<pair<int, int>> cur) {
    __int128 res = hsh1(cur);
    res *= m2;
    res += hsh2(cur);
    return res;
}

__int128 merge(long long a, long long b) {
    __int128 res = a;
    res *= m2;
    res += b;
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
//    cin.exceptions(cin.failbit);
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
    int n = int(a.size());
    a.push_back(cur);

    for (int i = 256; i >= 64; --i) {
        pair<int, int> sol{1e9, 1e9};
//        map<multiset<int>, int> seen;
        indexed_set<pair<int, int>> range;
        unordered_map<__int128, int> seen;
        for (int j = 0; j < i; ++j) {
            range.insert({a[j], j});
        }

        long long cur_hsh1 = hsh1(range), cur_hsh2 = hsh2(range);
        seen[merge(cur_hsh1, cur_hsh2)] = 0;
//        seen[range] = 0;
        for (int j = 1; j + i - 1 < n; ++j) {
            int ind = range.order_of_key(pair<int, int>{a[j - 1], j - 1});
            cur_hsh1 -= a[j - 1] * pw1[j - ind - 1];
            cur_hsh1 = (cur_hsh1 + m1) % m1;
            cur_hsh2 -= a[j - 1] * pw2[j - ind - 1];
            cur_hsh2 = (cur_hsh2 + m2) % m2;



//            range.erase(range.find(a[j - 1]));
//            range.insert(a[j + i - 1]);
            __int128 cur_hsh = merge(cur_hsh1, cur_hsh2);
            if (seen.find(cur_hsh) != seen.end()) {
                if (seen[cur_hsh] + i - 1 < j) {
                    sol = min(sol, pair<int, int>(seen[cur_hsh], j));
                }
            } else {
                seen[cur_hsh] = j;
            }
        }
        if (sol != pair<int, int>(1e9, 1e9)) {
            cout << i << "\n" << sol.first << "\n" << sol.second << "\n";
            return 0;
        }
    }
    cout << "no key\n";
}