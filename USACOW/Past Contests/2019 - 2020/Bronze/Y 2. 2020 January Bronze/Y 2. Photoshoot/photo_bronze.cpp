/*
ID: izhang01
TASK: photo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
}

const int maxn = 1e3 + 1;
bool used[maxn];

int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    vector<int> a(n);
    for (int start = 1; start < n + 1; ++start) {
        for (int j = 1; j < n + 1; ++j) {
            used[j] = false;
        }
        used[start] = true;
        a[0] = start;
        bool pos = true;
        for (int j = 1; j < n; ++j) {
            int next = b[j - 1] - a[j - 1];
            if (next <= 0 || used[next]) {
                pos = false;
                break;
            }
            used[next] = true;
            a[j] = next;
        }
        if (pos) {
            cout << a[0];
            for (int j = 1; j < n; ++j) {
                cout << " " << a[j];
            }
            cout << "\n";
            return 0;
        }
    }
}
