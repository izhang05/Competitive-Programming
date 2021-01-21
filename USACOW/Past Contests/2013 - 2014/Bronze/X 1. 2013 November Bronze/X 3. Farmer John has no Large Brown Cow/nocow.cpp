/*
ID: izhang01
TASK: nocow
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nocow.in", "r", stdin);
    freopen("nocow.out", "w", stdout);
}

const int maxn = 100;

vector<set<string> > adj(30);
int num_adj;

//vector<int> get_cow(int k, int total, int cur_adj, vector<int> sol) {
//    if (cur_adj == -1) {
//        sol.push_back(k - 1);
//    }
//    if (cur_adj >= 0) {
//        int add = (min((max(0, k - 1)) / total, (int) adj[cur_adj + 1].size() - 1));
//        sol.push_back(add);
//        cout << add << " " << adj[cur_adj + 1].size() << " " << cur_adj + 1 << "\n";
//        return (get_cow(k - add * total, total / (int) adj[cur_adj].size(), cur_adj - 1, sol));
//    }
//    return sol;
//}

vector<int> get_cow(int k, int total, int cur_adj, vector<int> sol) {
    if (cur_adj == num_adj - 1) {
        sol.push_back(max(0, k - 1));
        return sol;
    }
    int add = (min((max(0, k - 1)) / total, (int) adj[cur_adj].size() - 1));
    sol.push_back(add);
//        cout << add << " " << adj[cur_adj].size() << " " << cur_adj << endl;
    return (get_cow(k - add * total, total / (int) adj[cur_adj + 1].size(), cur_adj + 1, sol));

}

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    string s;
    vector<vector<string> > c(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> s;
        }
        num_adj = 0;
        while (true) {
            cin >> s;
            if (s == "cow.") {
                break;
            }
            c[i].push_back(s);
            adj[num_adj].insert(s);
            ++num_adj;
        }
    }

    vector<map<string, int> > indexes(num_adj);
    vector<map<int, string> > ind_to_adj(num_adj);
    int ind;
    for (int i = 0; i < num_adj; ++i) {
        ind = 0;
        for (string j : adj[i]) {
            indexes[i][j] = ind;
            ind_to_adj[i][ind] = j;
            ++ind;
        }
    }
//    for (auto i : c) {
//        for (string j : i) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
    vector<vector<int> > cow(n);
    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < num_adj; ++j) {
            v.push_back(indexes[j][c[i][j]]);
        }
        cow[i] = v;
    }
    sort(cow.begin(), cow.end());
    int total = 1;
    for (int i = 0; i < num_adj - 1; ++i) {
        total *= adj[i].size();
    }
    vector<int> cur = get_cow(k, total, 0, vector<int>{});
    int pre_ind = -1;
    ind = 0;
    while (ind != pre_ind) {
        pre_ind = ind;
        if (ind < cow.size()) {
            while (cow[ind] <= cur) {
                ++ind;
                if (ind >= cow.size()) {
                    break;
                }
            }
        }
        cur = get_cow(k + ind, total, 0, vector<int>{});
//        cout << k + ind << "\n";
//        for (int i : cur) {
//            cout << i << " ";
//        }
//        cout << endl;
    }
    cout << ind_to_adj[0][cur[0]];
    for (int i = 1; i < num_adj; ++i) {
        cout << " " << ind_to_adj[i][cur[i]];
    }
    cout << "\n";
    return 0;
}
