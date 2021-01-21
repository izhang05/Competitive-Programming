/*
ID: izhang01
TASK: sprime
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
}

set<int> sol;

bool prime(int n) {
    if (n == 2) {
        return true;
    }
    if (n == 1 || n % 2 == 0) {
        return false;
    }
    for (int i = 3; i < int(pow(n, 0.5)); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void start_dfs(int n, int digit) {
    if (!dist) {
        if (prime(node)) {
            sol.insert(node);
        }
        return;
    }
    for (int i : vector<int>{1, 3, 7, 9}) {
        node *= 10;
        node += i;
        if (prime(node)) {
            start_dfs(node, dist - 1);
        }
        node -= i;
        node /= 10;
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    start_dfs(2, n - 1);
    start_dfs(3, n - 1);
    start_dfs(5, n - 1);
    start_dfs(7, n - 1);

    for (int i : sol) {
        cout << i << "\n";
    }
    return 0;
}
