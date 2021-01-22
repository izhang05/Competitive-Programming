/*
ID: izhang01
TASK: reduce
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
}
const int maxn = 5e4 + 5;

vector<pair<int, int>> a, x, y, rev_x, rev_y;

template<class T>
void print(T temp) {
    for (auto i : temp) {
        cout << i << " ";
    }
    cout << "\n";
}


int sol = 2e9, n;

bool valid(pair<int, int> x, int l, int r, int b, int t) {
    return x.first >= l && x.first <= r && x.second >= b && x.second <= t;
}

void solve(vector<int> state, int cur) { //state {l, r, b, t}
    vector<vector<pair<int, int>>> m{x, rev_x, y, rev_y};

    if (cur > 3) {
        int cur_sol = (rev_x[state[1]].first - x[state[0]].first) * (rev_y[state[3]].first - y[state[2]].first);
        int count = 0;
        for (pair<int, int> i : a) {
            if (!valid(i, x[state[0]].first, rev_x[state[1]].first, y[state[2]].first, rev_y[state[3]].first)) {
                ++count;
            }
        }
        if (count <= 3) {
            sol = min(sol, cur_sol);
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        state[cur] = i;
        solve(state, cur + 1);
    }
}

int main() {
    setIO();
    cin >> n;
    a.resize(n), x.resize(n), y.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        x[i] = {a[i].first, i};
        y[i] = {a[i].second, i};
    }
    sort(x.begin(), x.end());
    rev_x.insert(rev_x.end(), x.begin(), x.end());
    reverse(rev_x.begin(), rev_x.end());

    sort(y.begin(), y.end());
    rev_y.insert(rev_y.end(), y.begin(), y.end());
    reverse(rev_y.begin(), rev_y.end());

    solve(vector<int>{0, 0, 0, 0}, 0);
    cout << sol << "\n";
    return 0;
}
