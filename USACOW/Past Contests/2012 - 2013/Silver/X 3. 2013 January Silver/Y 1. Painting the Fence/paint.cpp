/*
ID: izhang01
TASK: paint
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
}


int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    vector<pair<int, char>> positions;
    positions.emplace_back(0, '\0');
    set<int> pos_set;
    pos_set.insert(0);
    int pos = 0;
    int p;
    char d;
    for (int i = 0; i < n; ++i) {
        cin >> p >> d;
        if (d == 'R') {
            pos += p;
        } else {
            pos -= p;
        }
        pos_set.insert(pos);
        positions.emplace_back(pos, d);
    }
    map<int, int> loc_to_ind;
    map<int, int> ind_to_loc;
    int ind = 0;
    for (int i : pos_set) {
        loc_to_ind[i] = ind;
        ind_to_loc[ind] = i;
        ++ind;
    }
    map<int, int> coats;
    for (int i = 0; i < ind; ++i) {
        coats[i] = 0;
    }
    int pre = positions[0].first;
    for (int i = 1; i < positions.size(); ++i) {
        if (positions[i].second == 'R') {
            ++coats[loc_to_ind[pre]];
            --coats[loc_to_ind[positions[i].first]];
        } else {
            ++coats[loc_to_ind[positions[i].first]];
            --coats[loc_to_ind[pre]];
        }
        pre = positions[i].first;
    }
    int sol = 0;
    int cur = 0;
    for (int i = 0; i < ind - 1; ++i) {
        cur += coats[i];
        if (cur >= k) {
            sol += ind_to_loc[i + 1] - ind_to_loc[i];
        }
    }
    cout << sol << "\n";
    return 0;
}
