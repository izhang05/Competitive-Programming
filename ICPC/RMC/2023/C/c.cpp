#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;

    cin >> n >> m >> q;

    vector<string> arr(n);

    vector<bool> isgood(n, true);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < q; i++){
        int x;
        char c;

        cin >> x >> c;

        for(int j = 0; j < n; j++) if(arr[j][x - 1] != c) isgood[j] = false;
    }

    int ans = -1;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(isgood[i]){
            ans = i;
            cnt++;
        }
    }

    if(cnt > 1){
        cout << "ambiguous\n" << cnt;
        return 0;
    }

    cout << "unique" << "\n" << ans + 1;
}
