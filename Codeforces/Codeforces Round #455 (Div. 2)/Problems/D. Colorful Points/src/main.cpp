#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char, int> > groups;
    groups.emplace_back(s[0], 1);
    char pre = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] == pre) {
            ++groups.back().second;
        } else {
            groups.emplace_back(s[i], 1);
            pre = s[i];
        }
    }
    int sol = 0;
    while (groups.size() > 1) {
        vector<int> to_erase;
        if (--groups[0].second <= 0) {
            to_erase.push_back(0);
        }
        for (int i = 1; i < groups.size() - 1; ++i) {
            groups[i].second -= 2;
            if (groups[i].second <= 0) {
                to_erase.push_back(i);
            }
        }
        if (--groups[groups.size() - 1].second <= 0) {
            to_erase.push_back(groups.size() - 1);
        }
        sort(to_erase.begin(), to_erase.end());
        for (int i = 0; i < to_erase.size(); ++i) {
            groups.erase(groups.begin() + to_erase[i] - i);
        }

        to_erase.clear();
        for (int i = 0; i < max((int) groups.size(), 1) - 1; ++i) {
            if (groups[i].first == groups[i + 1].first) {
                to_erase.push_back(i);
            }
        }
        sort(to_erase.begin(), to_erase.end());

        for (int i = 0; i < to_erase.size(); ++i) {
            groups[to_erase[i] - i + 1].second += groups[to_erase[i] - i].second;
            groups.erase(groups.begin() + to_erase[i] - i);
        }
        ++sol;
    }
    cout << sol << "\n";
    return 0;
}
