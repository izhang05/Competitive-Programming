#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

struct mine {
    int g;
    double a, b;
};


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int g;
        double a, b;
        if (n == 1) {
            cin >> g >> a >> b;
            double first = g * b / (a + b);
            double second = g * a / (a + b);
            cout << setprecision(7) << first << " " << second << "\n";
        } else {
            vector<vector<double> > mine;
            cin >> g >> a >> b;
            mine.push_back({static_cast<double>(g), a, b});
            cin >> g >> a >> b;
            mine.push_back({static_cast<double>(g), a, b});
            double a_sol, b_sol = 0;
            if (mine[0][1] < mine[1][1]) {
                if (mine[0][2] < mine[1][2]) {
                    double g = mine[0][0], a = mine[0][1], b = mine[0][2];
                    a_sol = g * b / (a + b);
                    b_sol = g * a / (a + b);
                    g = mine[1][1], a = mine[1][1], b = mine[1][2];
                    a_
                } else {
                    a_
                }
            }
        }
    }
    return 0;
}
