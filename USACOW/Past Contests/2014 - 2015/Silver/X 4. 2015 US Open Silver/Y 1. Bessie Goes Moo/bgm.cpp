/*
ID: izhang01
TASK: bgm
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bgm.in", "r", stdin);
    freopen("bgm.out", "w", stdout);
}

map<char, vector<int> > values;
map<char, int> var_vals;
int sol;

void recurse(vector<char> vars, int i) {
    if (i == vars.size()) {
//        cout << cur << "\n";
        long long cur = 0;
        for (char i : vars) {
            cur += var_vals[i];
        }
        if (cur % 7 != 0) {
//            cout << cur << "\n";
            ++sol;
        }
    }
    for (int j : values[vars[i]]) {
        var_vals[vars[i]] = j;
        recurse(vars, i + 1);
    }
}

int main() {
    setIO();
    int n, a;
    cin >> n;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c >> a;
        if (values.find(c) != values.end()) {
            values[c].push_back(a);
        }
    }
    recurse(vector<char>{'B', 'E', 'S', 'S', 'I', 'E'}, 0);
    long long not_seven = sol;
    sol = 0;
    recurse(vector<char>{'G', 'O', 'E', 'S'}, 0);
    not_seven *= sol;
    sol = 0;
    recurse(vector<char>{'M', 'O', 'O'}, 0);
    not_seven *= sol;

    long long total = 1;
    for (auto i : values) {
        total *= max(1LL, (long long) i.second.size());
    }
    cout << total - not_seven << "\n";
    return 0;
}
