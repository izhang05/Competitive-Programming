/* Author: izhang
 * Time: 01-01-2024 14:29:40
**/
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
    T polygonArea2(vector<Point<T>>

                   &v) {
        T a = v.back().cross(v[0]);
        rep(i, 0, sz(v) - 1) a += v[i].
                    cross(v[i + 1]);
        return
                a;
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
//using namespace kactl;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n = 7;
    vector<kactl::Point<long double>> a(n);
    for (auto &i: a) {
        cin >> i.x >> i.y;
    }
    long double p;
    cin >> p;
    vector<int> perm(7);
    vector<int> sol{100};
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }
    do {
        vector<kactl::Point<long double>> cur(n);
        for (int i = 0; i < n; ++i) {
            cur[i] = a[perm[i]];
        }
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || (i + 1) % n == j || (j + 1) % n == i) {
                    continue;
                }
                if (!kactl::segInter(cur[i], cur[(i + 1) % n], cur[j], cur[(j + 1) % n]).empty()) {
                    bad = true;
                }
            }
        }
        if (bad) {
            continue;
        }
        long double area = abs(kactl::polygonArea2(cur)) / 2;
//        if (abs((area / 4) * (area / 4) * (area / 4) - p) <= 1e-5) {
//            cout << abs((area / 4) * (area / 4) * (area / 4) - p) << " " << p << "\n";
//        }
        if (abs(abs((area / 4) * (area / 4) * (area / 4) - p) <= 1e-5)) {
            sol = min(sol, perm);
        }
    } while (next_permutation(perm.begin(), perm.end()));
    for (auto &i: sol) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
