/*
ID: izhang01
TASK: auto
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);
    int w, n;
    cin >> w >> n;
    vector<pair<string, int> > dict(w); // first is word, second is index
    for (int i = 0; i < w; ++i) {
        cin >> dict[i].first;
        dict[i].second = i + 1;
    }
    sort(dict.begin(), dict.end());
    string s;
    int k;
    for (int i = 0; i < n; ++i) {
        cin >> k >> s;
        int low = 0, high = dict.size() - 1, mid, sol = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (dict[mid].first.substr(0, s.size()) == s) {
                sol = mid;
                high = mid - 1;
            } else if (dict[mid].first > s) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (sol == -1) {
            cout << -1 << "\n";
        } else if (sol + k - 1 < dict.size() && dict[sol + k - 1].first.substr(0, s.size()) == s) {
            cout << dict[sol + k - 1].second << "\n";
        } else {
            cout << -1 << "\n";
        }
//        cout << s << " " << sol << "\n";
    }
    return 0;
}
