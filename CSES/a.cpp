#include <bits/stdc++.h>
#include <ostream>

using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long;

template<typename S, typename T>
void smax(S &a, const T &b) {
    if (a < b)
        a = b;
}
template<typename S, typename T>
void smin(S &a, const T &b) {
    if (a > b)
        a = b;
}

#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rng_seed(x) mt19937 rng(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
// #define int long long

const int MXN = 1e5 + 5, INF = 1e9 + 5;

struct Node {
    Node *a;
    Node *b;
    int val;
    Node(int val, Node *a, Node *b) : a(a), b(b), val(val) {}
    bool operator==(Node other) const {
        // cout <<"hi\n";
        // cout << this << endl;
        // cout << other << endl;
        if (other.a == nullptr) {
            return val == other.val;
        }
        return *a == *other.a && *b == *other.b;
    }
    friend std::ostream &operator<<(std::ostream &o, const Node cur) {
        if (cur.a == nullptr) {
            o << cur.val;
        } else {
            o << "(" << *cur.a << ", " << *cur.b << ")";
        }
        return o;
    }
};

deque<Node *> seq(string S) {
    deque<Node *> fail = {};
    deque<Node *> dq;
    for (int i = 0; i < (int) 3e4; i++) {
        dq.emplace_back(new Node(i, 0, 0));
    }

    for (const auto &p : S) {
        Node *f = dq.front();
        Node *f2 = dq[1];

        if (p == 'C') {
            dq.push_front(f);
        } else if (p == 'D') {
            dq.pop_front();
        } else if (p == 'L') {
            if (f->a == nullptr)
                return fail;
            dq.pop_front();
            dq.emplace_front(f->a);
        } else if (p == 'P') {
            dq.pop_front();
            dq.pop_front();
            dq.emplace_front(new Node(-1, f, f2));
        } else if (p == 'R') {
            if (f->b == 0)
                return fail;
            dq.pop_front();
            dq.emplace_front(f->b);
        } else if (p == 'S') {
            dq.pop_front();
            dq.pop_front();
            dq.emplace_front(f);
            dq.emplace_front(f2);
        } else if (p == 'U') {
            if (f->b == nullptr)
                return fail;
            dq.pop_front();
            dq.emplace_front(f->b);
            dq.emplace_front(f->a);
        }
    }
    //    for (auto i : dq) {
    //        cout << i << endl;
    //    }
    //    cout << endl;
    // cout<<dq.front()<<endl;
    return dq;
}

void solve() {
    string S, T;
    cin >> S >> T;
    deque<Node *> s = seq(S), t = seq(T);
    if (s.size() != t.size()) {
        cout << "False";
        return;
    }

    for (int i = 0; i < sz(s); i++) {
        //        cout << *s[i] << " " << *t[i] << " " << (*s[i] == *t[i]) << endl;
        if (!(*s[i] == *t[i])) {
            cout << "False";
            return;
        }
    }

    cout << "True";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;
    while (TC--) solve();
}