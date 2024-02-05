#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else

struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;

    /**
     * Author: Ulf Lundstrom
     * Date: 2009-02-26
     * License: CC0
     * Source: My head with inspiration from tinyKACTL
     * Description: Class to handle points in the plane.
     * 	T can be e.g. long double or long long. (Avoid int.)
     * Status: Works fine, used a lot
     */

    template<class T>
    int sgn(T x) { return (x > 0) - (x < 0); }

    template<class T>
    struct Point {
        typedef Point P;
        T x, y;

        explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

        bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }

        bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }

        P operator+(P p) const { return P(x + p.x, y + p.y); }

        P operator-(P p) const { return P(x - p.x, y - p.y); }

        P operator*(T d) const { return P(x * d, y * d); }

        P operator/(T d) const { return P(x / d, y / d); }

        T dot(P p) const { return x * p.x + y * p.y; }

        T cross(P p) const { return x * p.y - y * p.x; }

        T cross(P a, P b) const { return (a - *this).cross(b - *this); }

        T dist2() const { return x * x + y * y; }

        long double dist() const { return sqrt((long double) dist2()); }

        // angle to x-axis in interval [-pi, pi]
        long double angle() const { return atan2(y, x); }

        P unit() const { return *this / dist(); } // makes dist()=1
        P perp() const { return P(-y, x); } // rotates +90 degrees
        P normal() const { return perp().unit(); }

        // returns point rotated 'a' radians ccw around the origin
        P rotate(long double a) const {
            return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
        }

        friend ostream &operator<<(ostream &os, P p) {
            return os << "(" << p.x << "," << p.y << ")";
        }
    };

    /**
     * Author: chilli, Takanori MAEHARA
     * Date: 2019-10-31
     * License: CC0
     * Source: https://github.com/spaghetti-source/algorithm/blob/master/geometry/_geom.cc#L744
     * Description: Returns the area of the intersection of a circle with a
     * ccw polygon.
     * Time: O(n)
     * Status: Tested on GNYR 2019 Gerrymandering, stress-tested
     */

    typedef Point<long double> P;
#define arg(p, q) atan2(p.cross(q), p.dot(q))

    long double circlePoly(P c, long double r, vector<P> ps) {
        auto tri = [&](P p, P q) {
            auto r2 = r * r / 2;
            P d = q - p;
            auto a = d.dot(p) / d.dist2(), b = (p.dist2() - r * r) / d.dist2();
            auto det = a * a - b;
            if (det <= 0) return arg(p, q) * r2;
            auto s = max((long double) 0., -a - sqrt(det)), t = min((long double) 1., -a + sqrt(det));
            if (t < 0 || 1 <= s) return arg(p, q) * r2;
            P u = p + d * s, v = p + d * t;
            return arg(p, u) * r2 + u.cross(v) / 2 + arg(v, q) * r2;
        };
        auto sum = 0.0;
        rep(i, 0, sz(ps)) sum += tri(ps[i] - c, ps[(i + 1) % sz(ps)] - c);
        return sum;
    }

}
//using namespace kactl;

void test_case() {
    int n, r, w, h;
    cin >> n >> r >> w >> h;
    vector<kactl::Point<long double>> p(4);
    p[0].x = 0, p[0].y = 0, p[1].x = w, p[1].y = 0, p[2].x = w, p[2].y = h, p[3].x = 0, p[3].y = h;
    long double sol = 0;
    for (int i = 0; i < n; ++i) {
        long double x, y, v;
        cin >> x >> y >> v;
        long double a = kactl::circlePoly(kactl::Point<long double>{x, y}, r, p);
        sol += v * a / (w * h);
    }
    cout << fixed << setprecision(30) << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
