#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vi a(n);
    vector<set<int>> occ(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        occ[a[i]].insert(i);
    }
    for (int i = 1; i <)

}
