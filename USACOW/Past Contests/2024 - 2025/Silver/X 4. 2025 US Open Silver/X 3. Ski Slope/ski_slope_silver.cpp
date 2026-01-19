#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct ski {
    int p;
    long long d, e;
};

ski s[mxn];
long long val[mxn];
priority_queue<int> diff[mxn];
vector<pair<long long, long long>> res[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> s[i].p >> s[i].d >> s[i].e;
        --s[i].p;
    }
    for (int i = 1; i < n; ++i) {
        val[i] += val[s[i].p] + s[i].e;
        diff[i] = diff[s[i].p];
        diff[i].push(s[i].d);
        while (diff[i].size() > 11) {
            diff[i].pop();
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (!diff[i].empty()) {
                res[j].emplace_back(diff[i].top(), val[i]);
                diff[i].pop();
            } else {
                res[j].emplace_back(0, val[i]);
            }
        }
    }
    for (int i = 0; i < 11; ++i) {
        res[i].emplace_back(0, 0);
        sort(res[i].begin(), res[i].end());
        for (int j = 1; j < res[i].size(); ++j) {
            res[i][j].second = max(res[i][j].second, res[i][j - 1].second);
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int st, c;
        cin >> st >> c;
        cout << prev(lower_bound(res[c].begin(), res[c].end(), make_pair((long long) st, INFL)))->second << "\n";
    }
    return 0;
}
