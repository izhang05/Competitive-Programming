/*
ID: izhang01
TASK: assign
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("assign.in", "r", stdin);
    freopen("assign.out", "w", stdout);
}

const int maxn = 15;
int n, cur[maxn], sol = 0;
vector<pair<int, int>> d, s;

bool check() {
    if (all_of(d.begin(), d.end(), [](pair<int, int> i) { return cur[i.first] != cur[i.second]; })) {
        return all_of(s.begin(), s.end(), [](pair<int, int> i) { return cur[i.first] == cur[i.second]; });
    } else {
        return false;
    }
}

void gen(int a) {
    if (a == n) {
        if (check()) {
            ++sol;
        }
        return;
    }
    for (int i = 0; i < 3; ++i) {
        cur [a] = i;
        gen(a + 1);
    }
}

int main() {
    setIO();
    int k;
    cin >> n >> k;
    int a, b;
    char c;
    for (int i = 0; i < k; ++i) {
        cin >> c >> a >> b;
        --a, --b;
        if (c == 'D') {
            d.emplace_back(a, b);
        } else {
            s.emplace_back(a, b);
        }
    }
    gen(0);
    cout << sol << "\n";
    return 0;
}
