/*
ID: izhang01
TASK: exercise
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    freopen("exercise.out", "w", stderr);
}
//#define DEBUG
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int maxp = 1235, maxn = 1e4 + 5;
long long dp[maxp][maxn];

int n, m;
int main() {
    setIO();
    cin >> n >> m;
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        bool prime = true;
        for (int j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= (int) primes.size(); ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            int p = primes[i - 1];
            while (p <= j) {
                dp[i][j] += (p * dp[i - 1][j - p]) % m;
                dp[i][j] %= m;
                p *= primes[i - 1];
            }
#ifdef DEBUG
            cout << i << " " << j << " " << dp[i][j] << "\n";
#endif
        }
    }
    cout << dp[(int) primes.size()][n] << "\n";
    return 0;
}
