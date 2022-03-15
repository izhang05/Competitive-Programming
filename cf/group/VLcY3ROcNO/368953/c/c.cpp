#include "bits/stdc++.h"

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    vector<int> pf(n, 0);
    vector<int> sf(n, 0);

    pf[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            pf[i] = pf[i - 1] + 1;
        } else
            pf[i] = 1;
    }

    sf[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1])
            sf[i] = sf[i + 1] + 1;
        else
            sf[i] = 1;
    }

    int ans = max(pf[n - 1], sf[0]);
    for (int i = 1; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            ans = max(ans, pf[i] + sf[i + 1]);
        }
    }
    printf("%d\n", ans);
}