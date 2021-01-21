/*
ID: izhang01
TASK: greetings
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("greetings.in", "r", stdin);
    freopen("greetings.out", "w", stdout);
}


int main() {
    setIO();
    int b, e;
    cin >> b >> e;
    vector<pair<int, char>> b_mov(b), e_mov(e);
    for (int i = 0; i < b; ++i) {
        cin >> b_mov[i].first >> b_mov[i].second;
    }
    for (int i = 0; i < e; ++i) {
        cin >> e_mov[i].first >> e_mov[i].second;
    }

    int b_pos = 0, e_pos = 0, b_ind = 0, e_ind = 0, time, sol = 0, b_pre, e_pre;
    while (true) {
        b_pre = b_pos, e_pre = e_pos;
        time = min(b_mov[b_ind].first, e_mov[e_ind].first);
        if (b_mov[b_ind].second == 'L') {
            b_pos -= time;
        } else {
            b_pos += time;
        }

        if (e_mov[e_ind].second == 'L') {
            e_pos -= time;
        } else {
            e_pos += time;
        }
        if (b_pre < e_pre) {
            if (b_pos >= e_pos) {
                ++sol;
            }
        } else if (e_pre < b_pre) {
            if (e_pos >= b_pos) {
                ++sol;
            }
        }
        b_mov[b_ind].first -= time;
        e_mov[e_ind].first -= time;
        if (b_mov[b_ind].first == 0) {
            ++b_ind;
        }
        if (e_mov[e_ind].first == 0) {
            ++e_ind;
        }
        if (b_ind == b || e_ind == e) {
            break;
        }
    }
    if (b_ind != b) {
        b_pre = b_pos;
        for (int i = b_ind; i < b; ++i) {
            if (b_mov[i].second == 'L') {
                b_pos -= b_mov[i].first;
            } else {
                b_pos += b_mov[i].first;
            }
            if (b_pre < e_pos && b_pos >= e_pos) {
                ++sol;
            } else if (e_pos < b_pre && e_pos >= b_pos) {
                ++sol;
            }
            b_pre = b_pos;
        }
    }

    if (e_ind != e) {
        e_pre = e_pos;
        for (int i = e_ind; i < e; ++i) {
            if (e_mov[i].second == 'L') {
                e_pos -= e_mov[i].first;
            } else {
                e_pos += e_mov[i].first;
            }
            if (e_pre < b_pos && e_pos >= b_pos) {
                ++sol;
            } else if (b_pos < e_pre && b_pos >= e_pos) {
                ++sol;
            }
            e_pre = e_pos;
        }
    }

//    cout << b_pos << " " << e_pos << "\n";
    cout << sol << "\n";
    return 0;
}
