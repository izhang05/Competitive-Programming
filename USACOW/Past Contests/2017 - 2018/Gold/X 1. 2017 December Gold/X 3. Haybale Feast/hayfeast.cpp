/*
ID: izhang01
TASK: hayfeast
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
}


int main() {
#define int long long
    setIO();
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > hay(n);
    for (int i = 0; i < n; ++i) {
        cin >> hay[i].first >> hay[i].second;
    }
    int flavour = 0, i = 0;
    int sol = 1e9;
    map<int, int> spicy;
    for (int j = 0; j < n; ++j) {
        flavour += hay[j].first;
        if (spicy.find(hay[j].second) != spicy.end()) {
            ++spicy[hay[j].second];
        } else {
            spicy[hay[j].second] = 1;
        }
        if (flavour >= m) {
            while (flavour - hay[i].first >= m) {
                flavour -= hay[i].first;
                --spicy[hay[i].second];
                if (spicy[hay[i].second] == 0) {
                    spicy.erase(hay[i].second);
                }
                ++i;
            }
            auto it = spicy.end();
            --it;
            sol = min(sol, it->first);
        }
//        auto it = spicy.end();
//        --it;
//        cout << i << " " << j << " " << flavour << " " << sol << " " << it->first << " " << it->second << "\n";
    }
    cout << sol << "\n";
    return 0;
}
