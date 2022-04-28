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

struct node {
    int l, r, p;
};

void add(node &cur_node, int val) {
    if (cur_node.l == -1) {
        cur_node.l = val;
    } else {
        cur_node.r = val;
        if (cur_node.l > cur_node.r) {
            swap(cur_node.l, cur_node.r);
        }
    }
}

void test_case() {
    int n, q;
    cin >> n >> q;
    vector<node> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = {-1, -1, -1};
    }
    bool bad = false;
    while (q--) {
        int b, c;
        cin >> b >> c;
        if (a[c].p != -1 || b == c) {
            dbg() << "a[c].p != -1 || b == c";
            bad = true;
        }
        a[c].p = b;
        if (a[b].l != -1 && a[b].r != -1) {
            dbg() << "a[b].l != -1 && a[b].r != -1";
            bad = true;
        }
        add(a[b], c);
    }
    if (bad) {
        cout << -1 << "\n";
        return;
    }
    deque<int> avail;
    for (int i = 0; i < n; ++i) {
        if (a[i].l == -1) {
            avail.push_front(i);
            avail.push_front(i);
        } else if (a[i].r == -1) {
            avail.push_back(i);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i].p == -1) {
            if (avail.empty()) {
                dbg() << "no avail";
                cout << -1 << "\n";
                return;
            }
            add(a[avail.back()], i);
            a.pop_back();
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].r == -1 && a[i].l != -1) {
            dbg() << i << " " << a[i].r << " " << a[i].l;
            cout << -1 << "\n";
            return;
        }
    }
    queue<int> qu;
    qu.push(0);
    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        cout << cur << "\n";
        if (a[cur].l != -1) {
            qu.push(a[cur].l);
            qu.push(a[cur].r);
        }
    }
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
