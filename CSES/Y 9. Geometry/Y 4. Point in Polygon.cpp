#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
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
        P perp() const { return P(-y, x); }       // rotates +90 degrees
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
     * Date: 2019-04-26
     * License: CC0
     * Source: https://vlecomte.github.io/cp-geo.pdf
     * Description: Returns true iff p lies on the line segment from s to e.
     * Use \texttt{(segDist(s,e,p)<=epsilon)} instead when using Point<double>.
     * Status:
     */

    template<class P>
    bool onSegment(P s, P e, P p) {
        return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
    }
    /**
     * Author: Ulf Lundstrom
     * Date: 2009-03-21
     * License: CC0
     * Source:
     * Description:\\
    \begin{minipage}{75mm}
    Returns the shortest distance between point p and the line segment from point s to e.
    \end{minipage}
    \begin{minipage}{15mm}
    \vspace{-10mm}
    \includegraphics[width=\textwidth]{content/geometry/SegmentDistance}
    \end{minipage}
     * Usage:
     * 	Point<double> a, b(2,2), p(1,1);
     * 	bool onSegment = segDist(a,b,p) < 1e-10;
     * Status: tested
     */

    typedef Point<double> P;
    double segDist(P &s, P &e, P &p) {
        if (s == e)
            return (p - s).dist();
        auto d = (e - s).dist2(), t = min(d, max(.0, (p - s).dot(e - s)));
        return ((p - s) * d - (e - s) * t).dist() / d;
    }

    /**
     * Author: Victor Lecomte, chilli
     * Date: 2019-04-26
     * License: CC0
     * Source: https://vlecomte.github.io/cp-geo.pdf
     * Description: Returns true if p lies within the polygon. If strict is true,
     * it returns false for points on the boundary. The algorithm uses
     * products in intermediate steps so watch out for overflow.
     * Time: O(n)
     * Usage:
     * vector<P> v = {P{4,4}, P{1,2}, P{2,1}};
     * bool in = inPolygon(v, P{3, 3}, false);
     * Status: stress-tested and tested on kattis:pointinpolygon
     */

    template<class P>
    int inPolygon(vector<P> &p, P a) {
        int cnt = 0, n = sz(p);
        rep(i, 0, n) {
            P q = p[(i + 1) % n];
            if (onSegment(p[i], q, a))
                return 2;
            //or: if (segDist(p[i], q, a) <= eps) return !strict;
            cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
        }
        return (bool) cnt;
    }

} // namespace kactl
//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("4");
    int n, m;
    cin >> n >> m;
    vector<kactl::Point<long long>> poly(n);
    for (int i = 0; i < n; ++i) {
        cin >> poly[i].x >> poly[i].y;
    }
    vector<kactl::Point<long long>> points(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    for (auto &i : points) {
        int res = kactl::inPolygon(poly, i);
        if (res == 0) {
            cout << "OUTSIDE"
                 << "\n";
        } else if (res == 1) {
            cout << "INSIDE"
                 << "\n";
        } else {
            cout << "BOUNDARY"
                 << "\n";
        }
    }

    return 0;
}
