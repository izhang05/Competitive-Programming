#include<bits/stdc++.h>

using namespace std;

bool moo(string &s) {
    return (s.size() == 3) && (s[1] == s[2]) && (s[0] != s[1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, f;
    cin >> n >> f;
    string s;
    cin >> s;
    map<string, int> cnt;
    for (int i = 0; i + 2 < n; ++i) {
        string cur = s.substr(i, 3);
        if (moo(cur)) {
            ++cnt[cur];
        }
    }
    set<string> sol;
    for (auto &i: cnt) {
        if (i.second >= f) {
            sol.insert(i.first);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            for (int j = max(0, i - 2); j <= i && j + 2 < n; ++j) {
                string cur = s.substr(j, 3);
                if (moo(cur)) {
                    --cnt[cur];
                }
            }
            char orig = s[i];
            s[i] = c;
            for (int j = max(0, i - 2); j <= i && j + 2 < n; ++j) {
                string cur = s.substr(j, 3);
                if (moo(cur)) {
                    if (++cnt[cur] >= f) {
                        sol.insert(cur);
                    }
                }
            }

            for (int j = max(0, i - 2); j <= i && j + 2 < n; ++j) {
                string cur = s.substr(j, 3);
                if (moo(cur)) {
                    --cnt[cur];
                }
            }
            s[i] = orig;
            for (int j = max(0, i - 2); j <= i && j + 2 < n; ++j) {
                string cur = s.substr(j, 3);
                if (moo(cur)) {
                    ++cnt[cur];
                }
            }
        }
    }

    cout << sol.size() << "\n";
    for (auto &i: sol) {
        cout << i << "\n";
    }
}
