#include <bits/stdc++.h>

using namespace std;

#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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

    double angle() const { return atan2(y, x); }

    P unit() const { return *this / dist(); }

    P perp() const { return P(-y, x); }

    P normal() const { return perp().unit(); }

    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }

    friend ostream &operator<<(ostream &os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

const long double eps = 1e-9;

template<class P>
bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= eps;
}

template<class P>
vector<P> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
            oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
        return {(a * ob - b * oa) / (ob - oa)};
    }
    set<P> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return {all(s)};
}

int main() {
    int n;
    cin >> n;

    vector<pair<Point<long double>, Point<long double>>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.x >> a[i].first.y >> a[i].second.x >> a[i].second.y;
    }

    map<Point<long double>, vector<int>> nodes;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<Point<long double>> inter = segInter(a[i].first, a[i].second, a[j].first, a[j].second);
            if (int(inter.size()) == 1) {
                Point<long double> cur = inter[0], cur_n_eps = cur, cur_p_eps = cur;
                cur_n_eps.x -= eps, cur_n_eps.y -= eps;
                cur_p_eps.x += eps, cur_p_eps.y += eps;
                if (nodes.lower_bound(cur_n_eps) == nodes.lower_bound(cur_p_eps)) {
                    nodes[cur].push_back(i);
                    nodes[cur].push_back(j);
                } else {
                    auto it = nodes.lower_bound(cur_n_eps);
                    it->second.push_back(i);
                    it->second.push_back(j);
                }
            }
        }
    }

    int num_nodes = 0;
    vector<Point<long double>> node_ind;
    vector<vector<int>> line_nodes(n);

    for (auto &i: nodes) {
        for (auto &j: i.second) {
            line_nodes[j].push_back(num_nodes);
        }
        node_ind[num_nodes++] = i.first;
    }
    int m = 0;
    for (auto &i: line_nodes) {
        m += (int) i.size() - 1;
    }



    for (auto &i: nodes) {
        sort(i.second.begin(), i.second.end(), [&a](auto left, auto right) {
            return (a[left].second - a[left].first).angle() < (a[right].second - a[right].first).angle();
        });
    }

    return 0;
}
