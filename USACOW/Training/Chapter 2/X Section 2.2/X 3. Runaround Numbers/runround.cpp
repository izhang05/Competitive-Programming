/*
ID: izhang01
TASK: runround
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
}

bool check(unsigned long long n) {
    set<int> seen;

}

int main() {
    setIO();
    int n;
    cin >> n;
    for (unsigned long long i = n + 1; !check(i); ++i) {
    }
    cout << n << "\n";
}
