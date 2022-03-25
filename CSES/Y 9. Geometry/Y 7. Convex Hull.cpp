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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
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
     * Author: Stjepan Glavina, chilli
     * Date: 2019-05-05
     * License: Unlicense
     * Source: https://github.com/stjepang/snippets/blob/master/convex_hull.cpp
     * Description:
    \\\begin{minipage}{75mm}
    Returns a vector of the points of the convex hull in counter-clockwise order.
    Points on the edge of the hull between two other points are not considered part of the hull.
    \end{minipage}
    \begin{minipage}{15mm}
    \vspace{-6mm}
    \includegraphics[width=\textwidth]{content/geometry/ConvexHull}
    \vspace{-6mm}
    \end{minipage}
     * Time: O(n \log n)
     * Status: stress-tested, tested with kattis:convexhull
    */

    typedef Point<ll> P;
    vector<P> convexHull(vector<P> pts) {
        if (sz(pts) <= 1)
            return pts;
        sort(all(pts));
        vector<P> h(sz(pts) + 1);
        int s = 0, t = 0;
        for (int it = 2; it--; s = --t, reverse(all(pts)))
            for (P p : pts) {
                while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
                h[t++] = p;
            }
        return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
    }
    /**
     * Author: Ulf Lundstrom
     * Date: 2009-03-21
     * License: CC0
     * Source:
     * Description: Returns where  is as seen from  towards . 1/0/-1 $\Leftrightarrow$ left/on line/right. If the optional argument  is given 0 is returned if  is within distance  from the line. P is supposed to be Point<T> where T is e.g. double or long long. It uses products in intermediate steps so watch out for overflow if using int or long long.
     * Usage:
     * 	bool left = sideOf(p1,p2,q)==1;
     * Status: tested
     */

    template<class P>
    int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

    template<class P>
    int sideOf(const P &s, const P &e, const P &p, double eps) {
        auto a = (e - s).cross(p - s);
        double l = (e - s).dist() * eps;
        return (a > l) - (a < -l);
    }
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
     * Author: chilli
     * Date: 2019-05-17
     * License: CC0
     * Source: https://github.com/ngthanhtrung23/ACM_Notebook_new
     * Description: Determine whether a point t lies inside a convex hull (CCW
     * order, with no collinear points). Returns true if point lies within
     * the hull. If strict is true, points on the boundary aren't included.
     * Usage:
     * Status: stress-tested
     * Time: O(\log N)
     */

    typedef Point<ll> P;

    bool inHull(const vector<P> &l, P p, bool strict = true) {
        int a = 1, b = sz(l) - 1, r = !strict;
        if (sz(l) < 3)
            return r && onSegment(l[0], l.back(), p);
        if (sideOf(l[0], l[a], l[b]) > 0)
            swap(a, b);
        if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p) <= -r)
            return false;
        while (abs(a - b) > 1) {
            int c = (a + b) / 2;
            (sideOf(l[0], l[c], p) > 0 ? b : a) = c;
        }
        return sgn(l[a].cross(l[b], p)) < r;
    }

} // namespace kactl
//using namespace kactl;

int main() {
    setIO("7");
    int n;
    cin >> n;
    vector<kactl::Point<long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    vector<kactl::Point<long long>> hull = kactl::convexHull(points), sol;
    for (auto &i : points) {
        if (!kactl::inHull(hull, i)) {
            sol.push_back(i);
        }
    }

    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.x << " " << i.y << "\n";
    }
    return 0;
}
