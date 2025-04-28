#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i =a; i < (b);++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
     * Author: Victor Lecomte, chilli
     * Date: 2019-05-05
     * License: CC0
     * Source: https://vlecomte.github.io/cp-geo.pdf
     * Description:\\
    \begin{minipage}{75mm}
    If a unique intersection point of the lines going through s1,e1 and s2,e2 exists \{1, point\} is returned.
    If no intersection point exists \{0, (0,0)\} is returned and if infinitely many exists \{-1, (0,0)\} is returned.
    The wrong position will be returned if P is Point<ll> and the intersection point does not have integer coordinates.
    Products of three coordinates are used in intermediate steps so watch out for overflow if using int or ll.
    \end{minipage}
    \begin{minipage}{15mm}
    \includegraphics[width=\textwidth]{content/geometry/lineIntersection}
    \end{minipage}
     * Usage:
     * 	auto res = lineInter(s1,e1,s2,e2);
     * 	if (res.first == 1)
     * 		cout << "intersection point at " << res.second << endl;
     * Status: stress-tested, and tested through half-plane tests
     */


    template<class P>
    pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
        auto d = (e1 - s1).cross(e2 - s2);
        if (d == 0) // if parallel
            return {-(s1.cross(e1, s2) == 0), P(0, 0)};
        auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
        return {1, (s1 * p + e1 * q) / d};
    }


    /**
     * Author: Victor Lecomte, chilli
     * Date: 2019-04-27
     * License: CC0
     * Source: https://vlecomte.github.io/cp-geo.pdf
     * Description:\\
    \begin{minipage}{75mm}
    If a unique intersection point between the line segments going from s1 to e1 and from s2 to e2 exists then it is returned.
    If no intersection point exists an empty vector is returned. If infinitely many exist a vector with 2 elements is returned, containing the endpoints of the common line segment.
    The wrong position will be returned if P is Point<ll> and the intersection point does not have integer coordinates.
    Products of three coordinates are used in intermediate steps so watch out for overflow if using int or long long.
    \end{minipage}
    \begin{minipage}{15mm}
    \includegraphics[width=\textwidth]{content/geometry/SegmentIntersection}
    \end{minipage}
     * Usage:
     * vector<P> inter = segInter(s1,e1,s2,e2);
     * if (sz(inter)==1)
     *   cout << "segments intersect at " << inter[0] << endl;
     * Status: stress-tested, tested on kattis:intersection
     */

    #include "OnSegment.h"

    template<class P>
    vector<P> segInter(P a, P b, P c, P d) {
        auto oa = c.cross(d, a), ob = c.cross(d, b),
                oc = a.cross(b, c), od = a.cross(b, d);
        // Checks if intersection is single non-endpoint point.
        if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
            return {(a * ob - b * oa) / (ob - oa)};
        set<P> s;
        if (onSegment(c, d, a)) s.insert(a);
        if (onSegment(c, d, b)) s.insert(b);
        if (onSegment(a, b, c)) s.insert(c);
        if (onSegment(a, b, d)) s.insert(d);
        return {all(s)};
    }

}
using namespace kactl;

const long double eps = 1e-12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point<long long>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    Point<long long> a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    for (int i = 0; i < n; ++i) {
        pair<int, Point<long long>> cur = lineInter(a, b, p[i], p[(i + 1) % n]);
        if (cur.first == -1) {
            cout << "?" << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] == a) {

        }
    }
    Point<long double> new_a{(long double) a.x, (long double) a.y};
    Point<long double> new_b{(long double) b.x + eps, (long double) b.y + eps};
    int cnt = 0;
    vector<Point<long double>> new_p(n);
    for (int i = 0; i < n; ++i) {
        new_p[i].x = p[i].x, new_p[i].y = p[i].y;
    }
    for (int i = 0; i < n; ++i) {
        if (lineInter(new_a, new_b, new_p[i], new_p[(i + 1) % n]).first == 1) {
            ++cnt;
        }
    }
    cout << (cnt % 2 == 1 ? "outside" : "inside") << "\n";
}
