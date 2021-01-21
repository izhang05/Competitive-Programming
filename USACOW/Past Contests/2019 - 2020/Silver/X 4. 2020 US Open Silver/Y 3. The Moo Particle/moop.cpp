/*
ID: izhang01
TASK: moop
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int> > particle(n);
    multiset<int> top, bot;
    for (int i = 0; i < n; ++i) {
        cin >> particle[i].first >> particle[i].second;
        bot.insert(particle[i].second);
    }
    sort(particle.begin(), particle.end());

    int sol = 1;
    for (int i = 0; i < n; ++i) {
        top.insert(particle[i].second);
        bot.erase(bot.find(particle[i].second));
        auto it = bot.rbegin();
        if (it != bot.rend()) {
            if (*top.begin() > *it) {
                ++sol;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
