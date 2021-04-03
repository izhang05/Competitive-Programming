/*
ID: izhang01
TASK: radio
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;


void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
}

const int maxn = 1001;
int n, m;
int dp[maxn][maxn];

vector<pair<int, int> > john(maxn);
vector<pair<int, int> > bessie(maxn);

int dist(int x, int y) {
    return (john[x].first - bessie[y].first) * (john[x].first - bessie[y].first) + (john[x].second - bessie[y].second) * (john[x].second - bessie[y].second);
}


int main() {
    setIO();
    cin >> n >> m;
    ++n, ++m;
    cin >> john[0].first >> john[0].second;
    cin >> bessie[0].first >> bessie[0].second;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'N') {
            john[i + 1].first = john[i].first;
            john[i + 1].second = john[i].second + 1;
        } else if (s[i] == 'S') {
            john[i + 1].first = john[i].first;
            john[i + 1].second = john[i].second - 1;
        } else if (s[i] == 'E') {
            john[i + 1].first = john[i].first + 1;
            john[i + 1].second = john[i].second;
        } else if (s[i] == 'W') {
            john[i + 1].first = john[i].first - 1;
            john[i + 1].second = john[i].second;
        }
    }
    cin >> s;
    for (int i = 0; i < m - 1; ++i) {
        if (s[i] == 'N') {
            bessie[i + 1].first = bessie[i].first;
            bessie[i + 1].second = bessie[i].second + 1;
        } else if (s[i] == 'S') {
            bessie[i + 1].first = bessie[i].first;
            bessie[i + 1].second = bessie[i].second - 1;
        } else if (s[i] == 'E') {
            bessie[i + 1].first = bessie[i].first + 1;
            bessie[i + 1].second = bessie[i].second;
        } else if (s[i] == 'W') {
            bessie[i + 1].first = bessie[i].first - 1;
            bessie[i + 1].second = bessie[i].second;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i < n - 1) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(i + 1, j));
                if (j < m - 1) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dist(i + 1, j + 1));
                }
            }
            if (j < m - 1) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dist(i, j + 1));
            }
        }
    }
    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}
