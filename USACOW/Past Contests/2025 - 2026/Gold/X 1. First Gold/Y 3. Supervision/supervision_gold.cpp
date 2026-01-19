#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, mxn = 1e6 + 5;
long long p2[mxn];


int main() {
    p2[0] = 1;
    for (int i = 1; i < mxn; ++i) {
        p2[i] = (p2[i - 1] * 2) % mod;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, d;
    cin >> n >> d;
    long long sol = 1;
    vector<long long> val(n), coaches, campers;
    int j = 0;
    long long sum = 0;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        int p, o;
        cin >> p >> o;
        if (o == 0) {
            // camper
            while (j < ind && coaches[j] < p - d) {
                auto it = lower_bound(campers.begin(), campers.end(), coaches[j]),
                        it2 = upper_bound(campers.begin(), campers.end(), coaches[j] + d);
                sum -= (val[j] * p2[it2 - it]) % mod;
                sum = ((sum % mod) + mod) % mod;
                ++j;
            }
            sol += sum;
            sol %= mod;
            sum *= 2;
            sum %= mod;
            campers.push_back(p);
        } else {
            // coach
            val[ind] = sol;
            sol *= 2;
            sol %= mod;
            coaches.push_back(p);
            sum += val[ind];
            sum %= mod;
            ++ind;
        }
    }
    cout << (sol - 1 + mod) % mod << "\n";
    return 0;
}
