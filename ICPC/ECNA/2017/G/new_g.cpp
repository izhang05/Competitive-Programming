#include <bits/stdc++.h>

using namespace std;

int n, m, ans;

vector<int> c;

int solve(int msk){
    int curcap = m, waited = 0, curans = 0;

    for(int i = 0; i < n; i++){
        if(waited >= 2) curcap = m;

        if((msk >> i) & 1){
            curans += min(curcap, c[i]);

            curcap = (curcap * 2) / 3;

            waited = 0;
        }
        else{
            waited++;
        }
    }

    return curans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    c.assign(n, 0);

    for(int i = 0; i < n; i++) cin >> c[i];

    for(int msk = 0; msk < (1 << n); msk++){
        ans = max(ans, solve(msk));
    }

    cout << ans;
}