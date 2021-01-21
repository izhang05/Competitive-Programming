/*
ID: izhang01
TASK: pprime
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
}

bool prime(long long n) {
    if (n == 2) {
        return true;
    }
    if (n == 1 || n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

vector<vector<int> > palindromes;

void generate(int len, vector<int> n) {
    if (n.size() == len) {
        palindromes.push_back(n);
        return;
    }
    if (!n.empty()) {
        for (int d = 0; d < 10; ++d) {
            n.push_back(d);
            generate(len, n);
            n.erase(--n.end());
        }
    } else {
        for (int d = 1; d < 10; ++d) {
            n.push_back(d);
            generate(len, n);
            n.erase(--n.end());
        }
    }
}

int main() {
    setIO();
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 5; ++i) {
        generate(i, vector<int>{});
    }
    vector<int> sol;
    for (auto i : palindromes) {
        long long cur = 0;
        for (int j : i) {
            cur *= 10;
            cur += j;
        }
        for (int j = i.size() - 2; j >= 0; --j) {
            cur *= 10;
            cur += i[j];
        }
        if (cur >= a && cur <= b && prime(cur)) {
            sol.push_back(cur);
        }
        cur = 0;
        for (int j : i) {
            cur *= 10;
            cur += j;
        }
        for (int j = i.size() - 1; j >= 0; --j) {
            cur *= 10;
            cur += i[j];
        }
        if (cur >= a && cur <= b && prime(cur)) {
            sol.push_back(cur);
        }
    }
    sort(sol.begin(), sol.end());
    for (int i : sol) {
        cout << i << "\n";
    }
    return 0;
}
