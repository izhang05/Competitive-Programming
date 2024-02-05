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
     * 	T can be e.g. double or long long. (Avoid int.)
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

        double dist() const { return sqrt((double) dist2()); }

        // angle to x-axis in interval [-pi, pi]
        double angle() const { return atan2(y, x); }

        P unit() const { return *this / dist(); } // makes dist()=1
        P perp() const { return P(-y, x); } // rotates +90 degrees
        P normal() const { return perp().unit(); }

        // returns point rotated 'a' radians ccw around the origin
        P rotate(double a) const {
            return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
        }

        friend ostream &operator<<(ostream &os, P p) {
            return os << "(" << p.x << "," << p.y << ")";
        }
    };

/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source: tinyKACTL
 * Description: Returns twice the signed area of a polygon.
 *  Clockwise enumeration gives negative area. Watch out for overflow if using int as T!
 * Status: Stress-tested and tested on kattis:polygonarea
 */


    template<class T>
    T polygonArea2(vector<Point<T>> &v) {
        T a = v.back().cross(v[0]);
        rep(i, 0, sz(v) - 1) a += v[i].cross(v[i + 1]);
        return a;
    }

    /**
     * Author: Ulf Lundstrom
     * Date: 2009-03-21
     * License: CC0
     * Source: Basic math
     * Description:\\
    \begin{minipage}{75mm}
    Returns the signed distance between point p and the line containing points a and b. Positive value on left side and negative on right as seen from a towards b. a==b gives nan. P is supposed to be Point<T> or Point3D<T> where T is e.g. double or long long. It uses products in intermediate steps so watch out for overflow if using int or long long. Using Point3D will always give a non-negative distance. For Point3D, call .dist on the result of the cross product.
    \end{minipage}
    \begin{minipage}{15mm}
    \includegraphics[width=\textwidth]{content/geometry/lineDistance}
    \end{minipage}
     * Status: tested
     */

    template<class P>
    long double lineDist(const P &a, const P &b, const P &p) {
        return (long double) (b - a).cross(p - a) / (b - a).dist();
    }

}
//using namespace kactl;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<kactl::Point<long double>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    long double a2 = kactl::polygonArea2(a), cur_area = 0;

    int p = 1;
    for (; p < n - 1; ++p) {
        vector<kactl::Point<long double>> cur{a[0], a[p], a[p + 1]};
        long double add_area = kactl::polygonArea2(cur);
        cur_area += add_area;
        if (cur_area * 2 >= a2) {
            cur_area -= add_area;
            break;
        }
    }
    long double diff = a2 / 2 - cur_area;
    kactl::Point<long double> seg = a[p + 1] - a[p];
    long double h = abs(kactl::lineDist(a[p], a[p + 1], a[0])), x = diff / h, alph = x / seg.dist();
    kactl::Point<long double> sol = a[p] + seg * alph;
    cout << fixed << setprecision(16) << sol.x << " " << sol.y << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
