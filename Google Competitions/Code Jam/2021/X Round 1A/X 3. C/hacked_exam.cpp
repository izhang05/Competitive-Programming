#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

#include <iostream>

using namespace std;

class Fraction {
private:
    // Calculates the greates common divisor with
    // Euclid's algorithm
    // both arguments have to be positive
    long long gcd(long long a, long long b) {
        while (a != b) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
        return a;
    }

public:
    long long numerator, denominator;

    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    Fraction(long long n, long long d) {
        if (d == 0) {
            cerr << "Denominator may not be 0." << endl;
            exit(0);
        } else if (n == 0) {
            numerator = 0;
            denominator = 1;
        } else {
            int sign = 1;
            if (n < 0) {
                sign *= -1;
                n *= -1;
            }
            if (d < 0) {
                sign *= -1;
                d *= -1;
            }

            long long tmp = gcd(n, d);
            numerator = n / tmp * sign;
            denominator = d / tmp;
        }
    }

    operator int() { return (numerator) / denominator; }
    operator float() { return ((float) numerator) / denominator; }
    operator double() { return ((double) numerator) / denominator; }
};

Fraction operator+(const Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
                 lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator+=(Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
                 lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
                 lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator-=(Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
                 lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.numerator * rhs.numerator,
                 lhs.denominator * rhs.denominator);
    return tmp;
}

Fraction operator*=(Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.numerator * rhs.numerator,
                 lhs.denominator * rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction &rhs) {
    Fraction tmp(lhs * rhs.numerator, rhs.denominator);
    return tmp;
}

Fraction operator*(const Fraction &rhs, int lhs) {
    Fraction tmp(lhs * rhs.numerator, rhs.denominator);
    return tmp;
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.numerator * rhs.denominator,
                 lhs.denominator * rhs.numerator);
    return tmp;
}

std::ostream &operator<<(std::ostream &strm, const Fraction &a) {
    if (a.denominator == 1) {
        strm << a.numerator;
    } else {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}

void solve() {
#ifdef DEBUG
    cout << "\n";
#endif
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s >> a[i].second;
        for (auto j : s) {
            a[i].first <<= 1;
            if (j == 'T') {
                ++a[i].first;
            }
        }
    }
    vector<int> nums(q);
    int pos = 0;
    for (int i = 0; i < (1 << q); ++i) {
        bool sol = true;
        for (int j = 0; j < n; ++j) {
#ifdef DEBUG
            cout << a[j].first << "\n";
#endif
            int cur = 0;
            for (int k = 0; k < q; ++k) {
                if ((a[j].first & (1 << k)) == (i & (1 << k))) {
                    ++cur;
                }
            }
            if (cur != a[j].second) {
#ifdef DEBUG
                cout << i << " " << cur << "\n";
#endif
                sol = false;
                break;
            }
        }
        if (sol) {
            ++pos;
            for (int j = 0; j < q; ++j) {
                if (i & (1 << j)) {
                    ++nums[j];
                }
            }
        }
    }
#ifdef DEBUG
    cout << "pos: " << pos << endl;
#endif
    Fraction sol;
    string s;
    for (int i = 0; i < q; ++i) {
        int take;
        if (pos - nums[i] > nums[i]) {
            take = pos - nums[i];
            s += 'F';
        } else {
            take = nums[i];
            s += 'T';
        }
        sol += Fraction{take, pos};
    }
    reverse(s.begin(), s.end());
    cout << s << " " << sol.numerator << "/" << sol.denominator << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
