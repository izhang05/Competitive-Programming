/* Author: izhang05
 * Time: 08-04-2021 18:46:24
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int mod = 1e9 + 7, inf = 1e9;

int main() {
    setIO("sprinklers");
    int sz;
    cin >> sz;
    vector<pair<int, int>> a(sz);
    for (int i = 0; i < sz; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int cur_mn = sz;
    vector<pair<int, int>> water;
    for (auto &i : a) {
        if (i.second < cur_mn) {
            water.push_back(i);
#ifdef DEBUG
            cout << i.first << " " << i.second << "\n";
#endif
            cur_mn = i.second;
        }
    }
#ifdef DEBUG
    cout << "\n";
#endif
    reverse(a.begin(), a.end());
    int cur_mx = 0;
    vector<pair<int, int>> fert;
    for (auto &i : a) {
        if (i.second > cur_mx) {
#ifdef DEBUG
            cout << i.first << " " << i.second << "\n";
#endif
            fert.push_back(i);
            cur_mx = i.second;
        }
    }
    if (fert.back().first != 0) {
        fert.emplace_back(0, 0);
    }
    reverse(fert.begin(), fert.end());
    int n = water.size(), m = fert.size(), i = 0, j = 0;
    int cur_water = sz - 1, cur_fert = sz - 1, height = 0;
    long long cur_add = 0, cur_sum = 0, sol = 0, total = 0;
    vector<int> last(sz, inf);
    for (int k = 1; k < m; ++k) {
        fert[k - 1].second = fert[k].second;
        fert[k].second = 0;
    }
    for (int x = 0; x < sz; ++x) {
        cur_sum += cur_add;
        cur_sum %= mod;
        if (height > 0) {
            total += height;
        }
        if (i < n && water[i].first == x) {
            for (int k = cur_water - 1; k >= water[i].second; --k) {
                last[k] = x;
                ++height;
                cur_add += height;
            }
            cur_water = water[i].second;
            ++i;
        }
#ifdef DEBUG
        cout << x << " " << sol << " " << height << " " << cur_sum << " " << cur_add << " " << total << "\n";
#endif
        if (height > 0) {
            sol += cur_sum;
            sol %= mod;
        }
        if (j < m && fert[j].first == x) {
            for (int k = cur_fert - 1; k >= fert[j].second; --k) {
                cur_add -= height;
#ifdef DEBUG
                cout << x << " " << k << " " << last[k] << "\n";
#endif
                if (last[k] != inf) {
                    cur_sum -= x - last[k];
                    total -= x - last[k];
                }
                cur_sum -= total;
                --height;
                cur_sum %= mod;
            }
            cur_fert = fert[j].second;
            ++j;
        }
        cur_sum %= mod;
#ifdef DEBUG
        cout << x << " " << sol << " " << height << " " << cur_sum << " " << cur_add << " " << total << "\n";
#endif
    }
    cout << sol << "\n";
    return 0;
}
