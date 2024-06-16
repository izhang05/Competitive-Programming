#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct rect {
    unsigned long long x1, x2, y1, y2;
};

bool in(unsigned long long test, unsigned long long a, unsigned long long b) {
    return test >= a && test <= b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q;
    cin >> n >> q;
    map<unsigned long long, rect> r;

    for (int i = 0; i < n; ++i) {
        unsigned long long ind;
        string tmp;
        cin >> ind >> tmp;
        if (tmp == "End") {
            cin >> r[ind].y2;
        } else {
            cin >> r[ind].y1;
            string hex_string;
            cin >> hex_string;

            std::stringstream ss;
            ss << std::hex << hex_string;
            ss >> r[ind].x1;

            unsigned long long t;
            cin >> t;
            r[ind].x2 = r[ind].x1 + t - 1;
        }
    }

    for (int i = 0; i < q; ++i) {
        string tmp;
        cin >> tmp;
        unsigned long long y1, y2, x1, x2;
        cin >> y1 >> y2;

        string h1, h2;
        cin >> h1 >> h2;

        std::stringstream ss;
        ss << std::hex << h1;
        ss >> x1;
        std::stringstream ss1;
        ss1 << std::hex << h2;
        ss1 >> x2;
//        cout << x1 << " " << x2 << "\n";

        set<unsigned long long> sol;
        for (auto &j: r) {
            if (in(j.second.x1, x1, x2) || in(j.second.x2, x1, x2)) {
                if (in(j.second.y1, y1, y2) || in(j.second.y2, y1, y2)) {
                    sol.insert(j.first);
                }
            }
        }
        int cur = 0;
        cout << sol.size() << " ";
        for (auto j: sol) {
            cout << j << " ";
            if (++cur >= 20) {
                break;
            }
        }
        cout << "\n";
    }
}