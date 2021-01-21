#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int t, a, b;
    vector<int> both, alice, bob;
    for (int i = 0; i < n; ++i) {
        cin >> t >> a >> b;
        if (a & b) {
            both.push_back(t);
        } else if (a) {
            alice.push_back(t);
        } else if (b) {
            bob.push_back(t);
        }
    }
    if (both.size() + alice.size() < k || both.size() + bob.size() < k) {
        cout << -1 << "\n";
        return 0;
    }
    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    long long bo_ind = 0, al_ind = 0, b_ind = 0, read = 0, sol = 0;
    while (read < k) {
        if (bo_ind < both.size() && al_ind < alice.size() && b_ind < bob.size()) {
            if (both[bo_ind] < alice[al_ind] + bob[b_ind]) {
                sol += both[bo_ind];
                ++bo_ind;
            } else {
                sol += alice[al_ind] + bob[b_ind];
                ++al_ind;
                ++b_ind;
            }
        } else if (bo_ind < both.size()) {
            sol += both[bo_ind];
            ++bo_ind;
        } else {
            sol += alice[al_ind] + bob[b_ind];
            ++al_ind;
            ++b_ind;
        }
        ++read;
    }
    cout << sol << "\n";
    return 0;
}
