#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()

template<class T>
int sgn(T x) { return (x > 0) - (x < 0); }

template<class T>
struct Point {
    typedef Point P;
    T x, y;

    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }

    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }

    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }

    T cross(P p) const { return x * p.y - y * p.x; }

    T cross(P a, P b) const { return (a - *this).cross(b - *this); }

    P perp() const { return P(-y, x); }
};

typedef Point<long double> P;

#define cmp(i, j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))
#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0

template<class P>
int extrVertex(vector<P> &poly, P dir) {
    int n = sz(poly), lo = 0, hi = n;
    if (extr(0)) return 0;
    while (lo + 1 < hi) {
        int m = (lo + hi) / 2;
        if (extr(m)) return m;
        int ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);
        (ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;
    }
    return lo;
}

#define cmpL(i) sgn(a.cross(poly[i], b))

template<class P>
array<int, 2> lineHull(P a, P b, vector<P> &poly) {
    int endA = extrVertex(poly, (a - b).perp());
    int endB = extrVertex(poly, (b - a).perp());
    if (cmpL(endA) < 0 || cmpL(endB) > 0)
        return {-1, -1};
    array<int, 2> res;
    rep(i, 0, 2) {
        int lo = endB, hi = endA, n = sz(poly);
        while ((lo + 1) % n != hi) {
            int m = ((lo + hi + (lo < hi ? 0 : n)) / 2) % n;
            (cmpL(m) == cmpL(endB) ? lo : hi) = m;
        }
        res[i] = (lo + !cmpL(hi)) % n;
        swap(endA, endB);
    }
    if (res[0] == res[1]) return {res[0], -1};
    if (!cmpL(res[0]) && !cmpL(res[1]))
        switch ((res[0] - res[1] + sz(poly) + 1) % sz(poly)) {
            case 0:
                return {res[0], res[0]};
            case 2:
                return {res[1], res[1]};
        }
    return res;
}

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    if (d == 0) {
        return {-(s1.cross(e1, s2) == 0), P(0, 0)};
    }
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}

long double dist(P a, P b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n, m;

vector<P> big, small;

vector<long double> distpref;

long double ans;

int main() {
    cin >> n >> m;

    big.resize(n);
    small.resize(m);

    for(int i = 0; i < n; i++){
        cin >> big[i].x >> big[i].y;
    }

    for(int i = 0; i < m; i++){
        cin >> small[i].x >> small[i].y;
    }

    distpref.assign(n, 0);

    for(int i = 0; i < n; i++) distpref[i] = dist(big[i], big[(i + 1) % n]);
    for(int i = 1; i < n; i++) distpref[i] += distpref[i - 1];

//    for(int i = 0; i < n; i++) cout << distpref[i] << " ";
//    cout << "\n";

    for(int i = 0; i < m; i++){
        array<int, 2> points = lineHull(small[i], small[(i + 1) % m], big);

        int a = points[0], b = points[1];

        assert(a != b);

        if(a < b){
            swap(a, b);

            long double curdist = distpref[n - 1] - (distpref[a - 1] - distpref[b]);

            auto[intercheck, inter] = lineInter(small[i], small[(i + 1) % m], big[a], big[(a + 1) % n]);

            curdist -= dist(big[a], inter);

            auto[intercheck2, inter2] = lineInter(small[i], small[(i + 1) % m], big[b], big[(b + 1) % n]);

            curdist -= dist(inter2, big[b + 1]);

            curdist = distpref[n - 1] - curdist;

            ans += curdist / distpref[n - 1] * dist(small[i], small[(i + 1) % m]);
        }
        else if(a > b){
            long double curdist = distpref[n - 1] - (distpref[a - 1] - distpref[b]);

            auto[intercheck, inter] = lineInter(small[i], small[(i + 1) % m], big[a], big[(a + 1) % n]);

            curdist -= dist(big[a], inter);

            auto[intercheck2, inter2] = lineInter(small[i], small[(i + 1) % m], big[b], big[(b + 1) % n]);

            curdist -= dist(inter2, big[b + 1]);

            ans += curdist / distpref[n - 1] * dist(small[i], small[(i + 1) % m]);
        }
    }

    cout << fixed << setprecision(16) << ans;
}
