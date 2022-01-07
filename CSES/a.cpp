#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define DEBUG

ld f(ld x, ld y) {
    return 50 / (5 - x * x);
}

ld euler(ld a, ld y_a, ld b, long long steps) {
#ifdef DEBUG
    cout << "Euler: \n";
#endif
    ld size = (ld) b / steps;
    ld res = y_a, x = a;
    for (int i = 0; i < steps; ++i) {
#ifdef DEBUG
        cout << "x: " << x << " y: " << res << " slope: " << f(x, res) << " next-y: " << res + f(x, res) * size << "\n";
#endif
        res += f(x, res) * size;
        x += size;
    }
    return res;
}

ld heun(ld a, ld y_a, ld b, long long steps) {
#ifdef DEBUG
    cout << "Heun: \n";
#endif
    ld size = (ld) b / steps;
    ld res = y_a, x = a, euler_y = y_a;
    for (int i = 0; i < steps; ++i) {
        euler_y = res + size * f(x, res);
        //        cout << euler_y << "\n";
        //        cout << (f(x, res) + f(x + size, euler_y)) / 2 << "\n";
        res += size * (f(x, res) + f(x + size, euler_y)) / 2;
        x += size;
        //        cout << "x: " << x << "\tres: " << res << "\n";
    }
    return res;
}

void run(ld a, ld y_a, ld b, long long steps) {
    cout << "Using starting value of y(" << a << ") = " << y_a << " and " << steps << " steps.\n";
    cout << euler(a, y_a, b, steps) << "\n";
    cout << "\n";
    cout << heun(a, y_a, b, steps) << "\n";
}

int main() {
    cout << fixed << setprecision(6);
    run(0, 6, 1, 4);
    return 0;
}
