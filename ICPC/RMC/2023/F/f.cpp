#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;

int n;

string str;

int states[N][N][3][3];

map<char, int> mp = {{'.', 0},
                     {'B', 1},
                     {'W', 2}};
map<int, char> revmp = {{0, '.'},
                        {1, 'B'},
                        {2, 'W'}};

vector<pair<int, int>> ans;

int solve(int l, int r, int lc, int rc) {
    if (states[l][r][lc][rc] != -1) return states[l][r][lc][rc];

    if (l == r) {
        return states[l][r][lc][rc] = 0;
    }

    string tempstr = str;

    tempstr[l] = revmp[lc];
    tempstr[r] = revmp[rc];

    set<int> values;

    for (int i = l; i + 1 <= r; i++) {
        if (tempstr[i] == 'B' && tempstr[i + 1] == 'W') {
            // go right
            values.insert(solve(l, i, lc, 0) ^ solve(i + 1, r, 1, rc));

            // go left
            values.insert(solve(l, i, lc, 2) ^ solve(i + 1, r, 0, rc));
        } else if (tempstr[i] == 'W' && tempstr[i + 1] == 'B') {
            // go right
            values.insert(solve(l, i, lc, 0) ^ solve(i + 1, r, 2, rc));

            // go left
            values.insert(solve(l, i, lc, 1) ^ solve(i + 1, r, 0, rc));
        }
    }

    int x = 0;

    while (values.find(x) != values.end()) x++;

    return states[l][r][lc][rc] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> str;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    memset(states, -1, sizeof(states));

    solve(0, n - 1, mp[str.front()], mp[str.back()]);

    int lc = mp[str.front()];
    int rc = mp[str.back()];

    for (int i = 0; i + 1 < n; i++) {
        if (str[i] == 'B' && str[i + 1] == 'W') {
            // go right

            if ((solve(0, i, lc, 0) ^ solve(i + 1, n - 1, 1, rc)) == 0) ans.push_back({i, i + 1});

            // go left

            if ((solve(0, i, lc, 2) ^ solve(i + 1, n - 1, 0, rc)) == 0) ans.push_back({i + 1, i});
        } else if (str[i] == 'W' && str[i + 1] == 'B') {
            // go right

            if ((solve(0, i, lc, 0) ^ solve(i + 1, n - 1, 2, rc)) == 0) ans.push_back({i, i + 1});

            // go left

            if ((solve(0, i, lc, 1) ^ solve(i + 1, n - 1, 0, rc)) == 0) ans.push_back({i + 1, i});
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";

    for (auto p: ans) cout << p.first + 1 << " " << p.second + 1 << "\n";
}
