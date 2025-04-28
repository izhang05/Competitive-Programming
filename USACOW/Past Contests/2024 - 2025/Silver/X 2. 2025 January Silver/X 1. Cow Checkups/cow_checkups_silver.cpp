#include <bits/stdc++.h>
using namespace std;

long long sol = 0;
int n;

long long ch(int x) {
    return (long long) x * (x - 1) / 2;
}

void solve(vector<int> a, vector<int> b){

}

int main() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    solve(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    solve(b, a);
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            sol += ch(i);
            sol += ch(n - (i + 1));
            sol += min(i + 1, n - i);
        }
    }
    cout << sol << "\n";
}