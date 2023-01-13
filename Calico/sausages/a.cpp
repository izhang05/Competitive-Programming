#define print_debug true

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const long long MOD = 1000000007;

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

typedef long long ll;

void fileIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// template <class T>
// void debug(const T& n) {
//     if (print_debug) //cerr << n << "\n\n";
// }

// template <class T>
// void debug(const vector<T>& k) {
//     if (print_debug) {
//         for (int i = 0; i < (int)k.size(); ++i) {
//             //cerr << k[i] << " ";
//         }
//         //cerr << "\n\n";
//     }
// }

// template <class T>
// void debug(const vector<vector<T>>& k) {
//     if (print_debug) {
//         for (int i = 0; i < (int)k.size(); ++i) {
//             for (int j = 0; j < (int)k[i].size(); ++j) {
//                 //cerr << k[i][j] << " ";
//             }
//             //cerr << "\n";
//         }
//         //cerr << "\n";
//     }
// }

template <class T>
int bin_upper(const vector<T>& k, const T& value) {
    return distance(k.begin(), upper_bound(k.begin(), k.end(), value));
}

template <class T>
int bin_lower(const vector<T>& k, const T& value) {
    return distance(k.begin(), lower_bound(k.begin(), k.end(), value));
}

// https://www.rookieslab.com/posts/extended-euclid-algorithm-to-find-gcd-bezouts-coefficients-python-cpp-code
vector<long long> extended_euclid_gcd(long long a, long long b) {
    // Returns a vector `result` of size 3 where:
    // Referring to the equation ax + by = gcd(a, b)
    //     result[0] is gcd(a, b)
    //     result[1] is x
    //     result[2] is y 
    
    long long s = 0; long long old_s = 1;
    long long t = 1; long long old_t = 0;
    long long r = b; long long old_r = a;

    while(r != 0) {
        long long quotient = old_r/r;
        // We are overriding the value of r, before that we store it"s current
        // value in temp variable, later we assign it to old_r
        long long temp = r;
        r = old_r - quotient*r;
        old_r = temp;

        // We treat s and t in the same manner we treated r
        temp = s;
        s = old_s - quotient*s;
        old_s = temp;

        temp = t;
        t = old_t - quotient*t;
        old_t = temp;
    }
    vector<long long> result;
    result.push_back(old_r);
    result.push_back(old_s);
    result.push_back(old_t);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> l(n), h(n);
        vector<pair<ll, ll>> updates;
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            updates.push_back({h[i], -1});
        }
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            updates.push_back({l[i], 1});
        }
        sort(updates.begin(), updates.end());
        vector<pair<ll, ll>> totals;
        totals.push_back({0, 0});
        for (int i = 0; i < updates.size(); ++i) {
            // //cerr << "updates: " << updates[i].first << " " << updates[i].second << "\n";
            if (totals.back().first == updates[i].first) {
                totals.back().second += updates[i].second;
            } else {
                totals.push_back({updates[i].first, totals.back().second + updates[i].second});
            }
        }

        for (int i = 0; i < totals.size(); ++i) {
            //cerr << totals[i].first << " " << totals[i].second << "\n";
        }

        ll lo = 1, hi = 1;
        ll curr_total = 0;
        pair<ll,ll> ans={-1,-1};
        //cerr << "------------------\n";
        while (lo < totals.size()-1) {
            //cerr << "lo: " << lo << " hi: " << hi << " curr_total: " << curr_total << "\n";
            if (curr_total < k) {
                //cerr << "too little\n";
                // move hi forwards
                if (hi == totals.size() - 1) {
                    break;
                }
                bool imposs = false;
                // check if too much first
                if (curr_total + totals[hi].second * (totals[hi + 1].first - totals[hi].first) > k) {
                    // too much, check for solutions
                    //cerr << "checking jump\n";

                    vector<ll> res = extended_euclid_gcd(totals[lo].second, totals[hi].second);
                    
                    if ((k - curr_total) % res[0] != 0) {
                        // impossible, move hi
                        imposs = true;
                    } else {
                        // DON'T FORGET CHANGE BOTTOM

                        // scale for gcd
                        res[1] *= (k - curr_total) / res[0];
                        res[2] *= (k - curr_total) / res[0];

                        // first one needs to be negative

                        // debug(res); 

                        ll a_bound = totals[lo+1].first - totals[lo].first;
                        ll b_bound = totals[hi+1].first - totals[hi].first;

                        if (res[1] > 0) {
                            //cerr << "first too high\n";
                            // res[1] -= totals[hi].second / gcd, res[2] += totals[lo].second / gcd
                            ll inc = totals[hi].second / res[0];
                            ll cnt = (res[1] - 0 + inc - 1) / inc;
                            res[1] -= cnt * inc;
                            res[2] += cnt * totals[lo].second / res[0];
                        }
                        if (res[2] > b_bound) {
                            //cerr << "second too high\n";
                            // res[1] += totals[hi].second / gcd, res[2] -= totals[lo].second / gcd
                            ll inc = totals[lo].second / res[0];
                            ll cnt = (res[2] - b_bound + inc - 1) / inc;
                            //cerr << "ASDHFAHSDFHF " << cnt << "\n";
                            res[1] += cnt * totals[hi].second / res[0];
                            res[2] -= cnt * inc;
                        }
                        if (res[1] < -a_bound) {
                            //cerr << "first too low\n";
                            ll inc = totals[hi].second / res[0];
                            ll cnt = (-a_bound - res[1] + inc - 1) / inc;
                            res[1] += cnt * inc;
                            res[2] -= cnt * totals[lo].second / res[0];
                        }
                        if (res[2] < 0) {
                            //cerr << "second too low\n";
                            ll inc = totals[lo].second / res[0];
                            ll cnt = (0 - res[2] + inc - 1) / inc;
                            res[1] -= cnt * totals[hi].second / res[0];
                            res[2] += cnt * inc;
                        }
                        if (res[1] > 0) {
                            //cerr << "first too high\n";
                            // res[1] -= totals[hi].second / gcd, res[2] += totals[lo].second / gcd
                            ll inc = totals[hi].second / res[0];
                            ll cnt = (res[1] - 0 + inc - 1) / inc;
                            res[1] -= cnt * inc;
                            res[2] += cnt * totals[lo].second / res[0];
                        }
                        if (res[2] > b_bound) {
                            //cerr << "second too high\n";
                            // res[1] += totals[hi].second / gcd, res[2] -= totals[lo].second / gcd
                            ll inc = totals[lo].second / res[0];
                            ll cnt = (res[2] - b_bound + inc - 1) / inc;
                            res[1] += cnt * totals[hi].second / res[0];
                            res[2] -= cnt * inc;
                        }

                        //cerr << "solutions: " << res[1] << " " << res[2] << "\n";

                        if (res[1] < -a_bound || res[1] > 0 || res[2] < 0 || res[2] > b_bound) {
                            imposs = true;
                        }

                        if (!imposs) {
                            // darn how to ext
                            ans={-res[1] + totals[lo].first, res[2] + totals[hi].first};
                            break;
                        }
                    }
                } else {
                    imposs = true;
                }
                if (imposs) {
                    curr_total += totals[hi].second * (totals[hi+1].first - totals[hi].first);
                    hi++;
                }

            } else if (curr_total == k) {
                // done
                ans={totals[lo].first, totals[hi].first};
                //cerr << "done" << lo << " " << totals[lo].first << "\n";
                break;
            } else {
                //cerr << "too much\n";
                // lo forward

                bool imposs = false;
                // check if too much first
                if (curr_total - totals[lo].second * (totals[lo + 1].first - totals[lo].first) < k) {
                    // too little, check for solutions

                    vector<ll> res = extended_euclid_gcd(totals[lo].second, totals[hi].second);

                    if ((k - curr_total) % res[0] != 0) {
                        // impossible, move lo
                        imposs = true;
                    } else {
                        res[1] *= (k - curr_total) / res[0];
                        res[2] *= (k - curr_total) / res[0];

                        ll a_bound = totals[lo+1].first - totals[lo].first;
                        ll b_bound = totals[hi+1].first - totals[hi].first;

                        if (res[1] > 0) {
                            //cerr << "first too high\n";
                            // res[1] -= totals[hi].second / gcd, res[2] += totals[lo].second / gcd
                            ll inc = totals[hi].second / res[0];
                            ll cnt = (res[1] - 0 + inc - 1) / inc;
                            res[1] -= cnt * inc;
                            res[2] += cnt * totals[lo].second / res[0];
                        }
                        if (res[2] > b_bound) {
                            //cerr << "second too high\n";
                            // res[1] += totals[hi].second / gcd, res[2] -= totals[lo].second / gcd
                            ll inc = totals[lo].second / res[0];
                            ll cnt = (res[2] - b_bound + inc - 1) / inc;
                            //cerr << "ASDHFAHSDFHF " << cnt << "\n";
                            res[1] += cnt * totals[hi].second / res[0];
                            res[2] -= cnt * inc;
                        }
                        if (res[1] < -a_bound) {
                            //cerr << "first too low\n";
                            ll inc = totals[hi].second / res[0];
                            ll cnt = (-a_bound - res[1] + inc - 1) / inc;
                            res[1] += cnt * inc;
                            res[2] -= cnt * totals[lo].second / res[0];
                        }
                        if (res[2] < 0) {
                            //cerr << "second too low\n";
                            ll inc = totals[lo].second / res[0];
                            ll cnt = (0 - res[2] + inc - 1) / inc;
                            res[1] -= cnt * totals[hi].second / res[0];
                            res[2] += cnt * inc;
                        }
                        if (res[1] > 0) {
                            //cerr << "first too high\n";
                            // res[1] -= totals[hi].second / gcd, res[2] += totals[lo].second / gcd
                            ll inc = totals[hi].second / res[0];
                            ll cnt = (res[1] - 0 + inc - 1) / inc;
                            res[1] -= cnt * inc;
                            res[2] += cnt * totals[lo].second / res[0];
                        }
                        if (res[2] > b_bound) {
                            //cerr << "second too high\n";
                            // res[1] += totals[hi].second / gcd, res[2] -= totals[lo].second / gcd
                            ll inc = totals[lo].second / res[0];
                            ll cnt = (res[2] - b_bound + inc - 1) / inc;
                            res[1] += cnt * totals[hi].second / res[0];
                            res[2] -= cnt * inc;
                        }

                        //cerr << "solutions: " << res[1] << " " << res[2] << "\n";

                        if (res[1] < -a_bound || res[1] > 0 || res[2] < 0 || res[2] > b_bound) {
                            imposs = true;
                        }

                        if (!imposs) {
                            // darn how to ext
                            ans={-res[1] + totals[lo].first, res[2] + totals[hi].first};
                            break;
                        }
                    }
                } else {
                    imposs = true;
                }
                if (imposs) {
                    curr_total -= totals[lo].second * (totals[lo+1].first - totals[lo].first);
                    lo++;
                }
            }
        }

        if (ans == pair<ll,ll>({-1,-1})) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans.first << " " << ans.second << "\n";
        }

    }

}