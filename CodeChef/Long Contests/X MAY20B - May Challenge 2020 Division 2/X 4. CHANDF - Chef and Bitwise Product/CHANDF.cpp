#include <bits/stdc++.h>

using namespace std;

unsigned long long F(unsigned long long x, unsigned long long y, unsigned long long z) {
    return ((x & z) * (y & z));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int t;
    cin >> t;
    unsigned long long x, y, l, r;
    while (t--) {
        cin >> x >> y >> l >> r;
        unsigned long long z = pow(2, floor(log2(max(x, y))));
        unsigned long long max_z = pow(2, floor(log2(max(x, y))) + 1);
        --z, --max_z;
        cout << max_z << "\n";
//        pair<unsigned long long, unsigned long long> solution{F(x, y, max_z), max_z};
//        for (; z < max_z; ++z) {
//            if (F(x, y, z) >= solution.first) {
//                solution.first = F(x, y, z);
//                solution.second = z;
//                break;
//            }
//        }
//        cout << solution.second << "\n";
    }
    return 0;
}
