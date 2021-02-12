#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int n = 48;
string path;
int sol = 0;
bool visited[7][7];

bool valid(pair<int, int> x) {
    return x.first >= 0 && x.second >= 0 && x.first < 7 && x.second < 7;
}

map<char, int> dx{{'D', 0},
                  {'U', 0},
                  {'L', -1},
                  {'R', 1}};

map<char, int> dy{{'D', 1},
                  {'U', -1},
                  {'L', 0},
                  {'R', 0}};
vector<char> dir{'D', 'U', 'L', 'R'};

void solve(int pos, pair<int, int> loc) {
    if (!valid(loc)) {
        return;
    }
    if (pos == 48) {
        ++sol;
        cout << sol << endl;
        return;
    }
    if (path[pos] != '?') {
        if (!visited[loc.first + dx[path[pos]]][loc.second + dy[path[pos]]]) {
            visited[loc.first + dx[path[pos]]][loc.second + dy[path[pos]]] = true;
            solve(pos + 1, make_pair(loc.first + dx[path[pos]], loc.second + dy[path[pos]]));
            visited[loc.first + dx[path[pos]]][loc.second + dy[path[pos]]] = false;
        }
    } else {
        for (char i : dir) {
            if (!visited[loc.first + dx[i]][loc.second + dy[i]]) {
                visited[loc.first + dx[i]][loc.second + dy[i]] = true;
                solve(pos + 1, make_pair(loc.first + dx[i], loc.second + dy[i]));
                visited[loc.first + dx[i]][loc.second + dy[i]] = false;
            }
        }
    }
}

int main() {
    setIO();
    cin >> path;
    solve(0, make_pair(0, 0));
    cout << sol << "\n";
    return 0;
}
