#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct fract {
    long long num{}, den{};

    fract(long long n, long long d) {
        num = n, den = d;
        long long g = __gcd(num, den);
        num /= g, den /= g;
    }


    bool operator==(const fract &other) const {
        return num * other.den == den * other.num;
    }

    bool operator<(const fract &other) const {
        return num * other.den < den * other.num;
    }

    bool operator<=(const fract &other) const {
        return *this < other || *this == other;
    }

    bool operator>(const fract &other) const {
        return num * other.den > den * other.num;
    }

    bool operator>=(const fract &other) const {
        return *this > other || *this == other;
    }

    fract operator+(const fract &other) const {
        long long g = lcm(den, other.den);
        return {num * (g / den) + other.num * (g / other.den), g};
    }

    fract operator-(const fract &other) const {
        long long g = lcm(den, other.den);
        return {num * (g / den) - other.num * (g / other.den), g};
    }

    fract operator*(long long other) const {
        return {num * other, den};
    }

    friend ostream &operator<<(ostream &os, const fract &fract) {
        os << "num: " << fract.num << " den: " << fract.den;
        return os;
    }
};

bool solve(int l, fract x, fract y, fract z) {
    if (l == 0) {
        return true;
    }
//    cout << l << " " << x << " " << y << " " << z << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                fract x_lo = fract(i, 3), x_hi = fract(i + 1, 3);
                fract y_lo = fract(j, 3), y_hi = fract(j + 1, 3);
                fract z_lo = fract(k, 3), z_hi = fract(k + 1, 3);
                if (x_lo < x && x < x_hi && y_lo < y && y < y_hi && z_lo < z && z < z_hi) {
//                    dbg() << i << " " << j << " " << k;
                    int num_one = int(i == 1) + int(j == 1) + int(k == 1);
                    if (num_one >= 2) {
                        return false;
                    }
                    x = x - x_lo;
                    y = y - y_lo;
                    z = z - z_lo;
                    return solve(l - 1, x * 3, y * 3, z * 3);
                }
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                fract x_lo = fract(i, 3), x_hi = fract(i + 1, 3);
                fract y_lo = fract(j, 3), y_hi = fract(j + 1, 3);
                fract z_lo = fract(k, 3), z_hi = fract(k + 1, 3);
                if (x_lo <= x && x <= x_hi && y_lo <= y && y <= y_hi && z_lo <= z && z <= z_hi) {
//                    dbg() << i << " " << j << " " << k;
                    int num_one = int(i == 1) + int(j == 1) + int(k == 1);
                    if (num_one >= 2) {
                        continue;
                    }
                    x = x - x_lo;
                    y = y - y_lo;
                    z = z - z_lo;
                    return solve(l - 1, x * 3, y * 3, z * 3);
                }
            }
        }
    }
    return false;
}

void test_case() {
    int l;
    fract x(0, 0), y(0, 0), z(0, 0);
    cin >> l >> x.num >> x.den >> y.num >> y.den >> z.num >> z.den;
    cout << solve(l, x, y, z) << "\n";
}

int main() {

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
