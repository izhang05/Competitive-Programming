#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct car {
    int t, f, ind, finishing;
    char s;

    friend ostream &operator<<(ostream &os, const car &car) {
        os << "t: " << car.t << " f: " << car.f << " ind: " << car.ind << " finishing: " << car.finishing << " s: "
           << car.s;
        return os;
    }
};

vector<int> sol;
int processed;

struct pump {
    queue<car> line[2];
    car pump[2][2]{}; // [left/right][A/B]
    bool occ[2][2]{};

    void process(int t) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (occ[i][j]) {
                    if (pump[i][j].finishing == t) {
                        sol[pump[i][j].ind] = t;
                        ++processed;
                        occ[i][j] = false;
                    }
                }
            }
        }
        for (int i = 0; i < 2; ++i) {
            while (!line[i].empty()) {
                if (!occ[i][0] && !occ[i][1]) {
                    occ[i][1] = true;
                    pump[i][1] = line[i].front();
                    pump[i][1].finishing = t + pump[i][1].f;
                    line[i].pop();
                } else if (!occ[i][0]) {
                    occ[i][0] = true;
                    pump[i][0] = line[i].front();
                    pump[i][0].finishing = t + pump[i][0].f;
                    line[i].pop();
                } else {
                    break;
                }

            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, n;
    cin >> p >> n;
    vector<car> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].t >> c[i].f >> c[i].s;
        c[i].ind = i;
    }
    std::reverse(c.begin(), c.end());
    sol.resize(n);

    vector<pump> pumps(p);

    int cur_t = 0;
    while (processed < n) {
//        cout << "time: " << cur_t << endl;
        for (int i = 0; i < p; ++i) {
            pumps[i].process(cur_t);
//            for (int j = 0; j < 2; ++j) {
//                for (int k = 0; k < 2; ++k) {
//                    cout << pumps[i].pump[j][k] << "\n";
//                }
//            }
//            cout << "line: " << "\n";
//            for (int j = 0; j < 2; ++j) {
//                cout << pumps[i].line[j].size() << "\n";
//            }
        }
        if (!c.empty() && c.back().t == cur_t) {
            int shortest = 1e9, ind = 0;
            int side;
            car cur_car = c.back();
//            cout << "adding: " << cur_car << "\n";
            c.pop_back();
            if (cur_car.s == 'L') {
                side = 0;
            } else {
                side = 1;
            }
            for (int i = 0; i < p; ++i) {
                if (!pumps[i].occ[side][0]) {
                    ind = i;
                    break;
                }
                if ((int) pumps[i].line[side].size() < shortest) {
                    shortest = (int) pumps[i].line[side].size();
                    ind = i;
                }
            }
//            cout << shortest << " " << ind << "\n";
            pumps[ind].line[side].push(cur_car);
//            cout << pumps[ind].line[side].size() << "\n";
            pumps[ind].process(cur_t);
//            cout << pumps[ind].line[side].size() << "\n";
        }
        ++cur_t;
    }

    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
}
