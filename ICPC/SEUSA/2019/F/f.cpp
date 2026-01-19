#include <bits/stdc++.h>

using namespace std;

const long double pi = 2 * acos(0);

struct star {
    long double t, s, a, dist;
};

long double dist(long double x, long double y) {
    if (x > y) {
        swap(x, y);
    }
    return min(y - x, x + 2 * pi - y);
}

long double mod(long double x, long double mod) {
    while (x >= mod) {
        x -= mod;
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    vector<star> b(n);
    long double cur = 0, diff = 0;
    vector<pair<long double, long double>> events;
    for (auto &i: b) {
        cin >> i.t >> i.s >> i.a;
        cur += max((long double) 0, i.t - i.s * dist(0, i.a));
        i.dist = min(pi, i.t / i.s);

        events.emplace_back(mod(i.a - i.dist + 2 * pi, 2 * pi), i.s);
        events.emplace_back(i.a, -2 * i.s);
        events.emplace_back(mod(i.a + i.dist, 2 * pi), i.s);
        if (i.a - i.dist < 0) {
            diff += i.s;
        } else if (i.a + i.dist >= 2 * pi) {
            diff -= i.s;
        }
    }
    sort(events.begin(), events.end());
    long double sol = cur, pre = 0;
    for (auto &i: events) {
        cur += dist(i.first, pre) * diff;
        diff += i.second;
        sol = max(sol, cur);
        pre = i.first;
    }
    cout << fixed << setprecision(18) << sol << "\n";
}
