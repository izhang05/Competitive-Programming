/*
ID: izhang01
TASK: wormhole
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int sol;
vector<pair<int, int> > points;
int n;
vector<int> values;
map<int, int> next_hole;
map<int, int> connected;
bool available[12];

bool pos() {
    for (int i = 0; i < n; ++i) {
        int hole = i;
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (next_hole[hole] == -1) {
                flag = false;
                break;
            }
            hole = connected[next_hole[hole]];
        }
        if (flag) {
            return true;
        }
    }
    return false;
}

void recurse(int cur) {
//    cout << cur << endl;
    if (cur >= n) {
        connected.clear();
        for (int i = 0; i < n / 2; ++i) {
//            cout << values[2 * i] << " " << values[2 * i + 1] << " ";
            connected[values[2 * i]] = values[2 * i + 1];
            connected[values[2 * i + 1]] = values[2 * i];

        }
        if (pos()) {
//            for (auto i : connected) {
//                cout << i.first << " " << i.second << endl;
//            }
//            cout << "\n";
//            for (int i : values) {
//                cout << i << " ";
//            }
//            cout << "\n";
            ++sol;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (available[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (available[j]) {
                    values[cur] = i;
                    values[cur + 1] = j;
                    available[j] = false;
                    available[i] = false;
                    recurse(cur + 2);
                    available[i] = true;
                    available[j] = true;
                }
            }
            break;
        }
    }
}


int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> n;
    points.resize(n);
    values.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].second >> points[i].first;
    }
    sort(points.begin(), points.end());
    for (int i = 0; i < n - 1; ++i) {
        available[i] = true;
        if (points[i].first == points[i + 1].first) {
            next_hole[i] = i + 1;
        } else {
            next_hole[i] = -1;
        }
    }
    next_hole[n - 1] = -1;
    available[n - 1] = true;
    recurse(0);
    cout << sol << "\n";
    return 0;
}
