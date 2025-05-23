#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vi A(N); F0R(i, N) cin >> A[i];
        map<int, vi> Pm;
        F0R(i, N) {
            Pm[A[i]].pb(i);
        }

        vector<vi> P; trav(a, Pm) P.pb(a.s);

        int cur = 0;
        int ans = 0;
        while (cur < sz(P)) {
            int cnt = sz(P[cur]);
            if (cur > 0) {
                F0R(i, sz(P[cur-1])) {
                    if (P[cur-1][i] < P[cur][0]) {
                        cnt++;
                    }
                }
            }
            cur++;
            while (cur < sz(P) && P[cur-1][sz(P[cur-1])-1] < P[cur][0]) {
                cnt += sz(P[cur]);
                cur++;
            }
            if (cur < sz(P)) {
                F0R(i, sz(P[cur])) {
                    if (P[cur][i] > P[cur-1][sz(P[cur-1]) - 1]) cnt++;
                }
            }
            ans = max(ans, cnt);
        }

        F0R(i, sz(P) - 1) {
            vector<pair<int, bool> > E;
            F0R(j, sz(P[i])) {
                E.pb({P[i][j], true});
            }
            F0R(j, sz(P[i+1])) {
                E.pb({P[i+1][j], false});
            }
            int cnt = sz(P[i+1]);
            ans = max(ans, cnt);
            sort(all(E));
            F0R(j, sz(E)) {
                if (E[j].s) {
                    cnt++;
                    ans = max(ans, cnt);
                } else {
                    cnt--;
                }
            }
        }

        cout << N-ans << nl;
    }

	return 0;
}

// read the question correctly (ll vs int)
// template by bqi343

