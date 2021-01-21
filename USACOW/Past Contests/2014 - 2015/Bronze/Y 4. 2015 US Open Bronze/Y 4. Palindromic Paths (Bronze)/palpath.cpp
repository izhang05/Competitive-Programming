/*
ID: izhang01
TASK: palpath
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
}

//bool is_palindrome(string s) {
//    string rev = s;
//    reverse(rev.begin(), rev.end());
//    return s == rev;
//}

const int maxn = 18;
string grid[maxn];

unordered_set<string> first;
int n;
unordered_set<string> sol;
int num_count = 0;

void first_dfs(int x, int y, string cur) {
    ++num_count;
    cur += grid[x][y];
    if (cur.size() == n - 1) {
        first.insert(cur);
//        cout << cur << "\n";
    }
    if (x != n - 1) {
        first_dfs(x + 1, y, cur);
    }
    if (y != n - 1) {
        first_dfs(x, y + 1, cur);
    }
    cur.pop_back();
}

void second_dfs(int x, int y, string cur) {
    cur += grid[x][y];
    if (cur.size() == n) {
//        cout << cur << "\n";
        if (first.find(cur.substr(0, cur.size() - 1)) != first.end()) {
            sol.insert(cur);
        }
//        cout << cur << "\n";
    }
    if (x != 0) {
        second_dfs(x - 1, y, cur);
    }
    if (y != 0) {
        second_dfs(x, y - 1, cur);
    }
    cur.pop_back();
}


int main() {
    setIO();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    first_dfs(0, 0, "");
    second_dfs(n - 1, n - 1, "");
    cout << sol.size() << "\n";
    cout << num_count << "\n";
    return 0;
}
