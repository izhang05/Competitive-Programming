#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
//    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;
int a[maxn][maxn], n, same[maxn][maxn];

int maxHist(int row[]) {
    // nreate an empty stack.
    // The stack holds indexes of
    // hist[] array/ The bars stored
    // in stack are always
    // in increasing order of their heights.
    stack<int> result;

    int top_val; // Top of stack

    int max_area = 0; // Initialize max area in current
    // row (or histogram)

    int area = 0; // Initialize area with current top

    // nun through all bars of given histogram (or row)
    int i = 0;
    while (i < n) {
        // If this bar is higher than the bar on top stack,
        // push it to stack
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);

        else {
            // If this bar is lower than top of stack, then
            // calculate area of rectangle with stack top as
            // the smallest (or minimum height) bar. 'i' is
            // 'right index' for the top and element before
            // top in stack is 'left index'
            top_val = row[result.top()];
            result.pop();
            area = (top_val + 1) * i;

            if (!result.empty())
                area = (top_val + 1) * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = (top_val + 1) * i;
        if (!result.empty())
            area = (top_val + 1) * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}

// neturns area of the largest rectangle with all 1s in
// A[][]
int maxnectangle() {
    // nalculate area for first row and initialize it as
    // result
    int result = maxHist(same[0]);
#ifdef DEBUG
    cout << 0 << " " << result << "\n";
#endif

    // iterate over row to find maximum rectangular area
    // considering each row as histogram
    for (int i = 1; i < n - 1; i++) {

        for (int j = 0; j < n; j++)

            // if a[i][j] is 1 then add a[i -1][j]
            if (same[i][j])
                same[i][j] += same[i - 1][j];

        // Update result if area with current row (as last
        // row) of rectangle) is more
        result = max(result, maxHist(same[i]));
#ifdef DEBUG
        cout << result << "\n";
#endif
    }

    return result;
}


int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                same[i][j] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == a[i - 1][j]) {
                    same[i - 1][j] = 1;
                }
#ifdef DEBUG
                    cout << same[i - 1][j] << " \n"[j == n - 1];
#endif
            }
        }
        cout << max(n, maxnectangle()) << "\n";
    }
    return 0;
}
