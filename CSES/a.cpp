#include <bits/stdc++.h>

using namespace std;

long double f(long double x, long double y) {
    return 3 - 2 * x - 0.5 * y;
}

int main() {
    int steps = 1000000000;
    long double x = 0, y = 1, b = 1, size = (long double) b / steps;
    for (int i = 0; i < steps; ++i, b += size) {
//        cout << "x: " << x << "\ty: " << y << "\n";
        y += f(x, y) * size;
        x += size;
    }
    cout << fixed << setprecision(16) << y << "\n";
    return 0;
}
