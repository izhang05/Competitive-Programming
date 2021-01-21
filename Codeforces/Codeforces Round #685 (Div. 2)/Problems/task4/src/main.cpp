#include <bits/stdc++.h>
#include <random>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long d, k;
        cin >> d >> k;
        set<int> pre;
        long long last;
        for (long long i = d / k + 1; i >= 0; --i) {
            if (pow(k * i, 2) + pow(k * i, 2) <= pow(d, 2)) {
                last = i;
                break;
            }
        }
        if ((last * k) * (last * k) + ((last + 1) * k) * ((last + 1) * k) <= d * d) {
            cout << "Ashish" << "\n";
        } else {
            cout << "Utkarsh" << "\n";
        }
    }
    return 0;
}
