#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

map<int, int> factorize(int x) {
    map<int, int> res;
    while (x % 2 == 0) {
        x /= 2;
        ++res[2];
    }
    for (long long i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            x /= int(i);
            ++res[i];
        }
    }
    if (x != 1) {
        ++res[x];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<map<int, int>> fact(n);
    map<int, multiset<int>> total;
    map<int, int> cur_gcd;
    for (int i = 0; i < n; ++i) {
        fact[i] = factorize(a[i]);
        for (auto j : fact[i]) {
            total[j.first].insert(j.second);
        }
    }
    long long sol = 1;
    for (const auto &i : total) {
        if (i.second.size() == n) {
            cur_gcd[i.first] = *i.second.begin();
            for (int j = 0; j < *i.second.begin(); ++j) {
                sol *= i.first;
                sol %= mod;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int loc, x;
        cin >> loc >> x;
        --loc;
        map<int, int> cur = factorize(x);
        for (auto j : cur) {
            fact[loc][j.first] += j.second;
            int val = fact[loc][j.first];
            if (val != j.second) {
                total[j.first].erase(total[j.first].find(val - j.second));
            }
            total[j.first].insert(val);
            if (total[j.first].size() == n) {
                if (*total[j.first].begin() != cur_gcd[j.first]) {
                    for (int k = 0; k < *total[j.first].begin() - cur_gcd[j.first]; ++k) {
                        sol *= j.first;
                        sol %= mod;
                    }
                    cur_gcd[j.first] = *total[j.first].begin();
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}