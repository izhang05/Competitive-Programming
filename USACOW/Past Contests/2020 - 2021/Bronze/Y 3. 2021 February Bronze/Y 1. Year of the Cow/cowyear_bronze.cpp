#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
//#define DEBUG

vector<string> zodiac{"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

int main() {
    setIO();
    int n;
    cin >> n;
    map<string, int> z, years;
    int ind = 0;
    for (auto i : zodiac) {
        z[i] = ind++;
    }
    years["Bessie"] = 0;
    for (int i = 0; i < n; ++i) {
        string a, _, dir, type, b;
        cin >> a >> _ >> _ >> dir >> type >> _ >> _ >> b;
        int cost;
        if (dir == "previous") {
            cost = -((((years[b] % 12) + 12) % 12 - z[type] + 12) % 12);
            if (cost == 0) {
                cost = -12;
            }
        } else {
            cost = (z[type] - ((years[b] % 12) + 12) % 12 + 12) % 12;
            if (cost == 0) {
                cost = 12;
            }
        }
        years[a] = years[b] + cost;
    }
#ifdef DEBUG
    for (auto j : years) {
        cout << j.first << " " << j.second << "\n";
    }
#endif
    cout << abs(years["Elsie"]) << "\n";
    return 0;
}
