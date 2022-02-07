/* Author: izhang
 * Time: 02-06-2022 09:35:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
map<array<int, 3>, int> mem;
int guess(int i, int j, int k) {
    array<int, 3> cur{i, j, k};
    sort(cur.begin(), cur.end());
    if (mem.find(cur) != mem.end()) {
        return mem[cur];
    }
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    cin >> mem[cur];
    if (mem[cur] == -1) {
        exit(0);
    }
    return mem[cur];
}
void answer(int i, int j) {
    cout << "! " << i + 1 << " " << j + 1 << endl;
}

vector<int> solve(const vector<int> &b) {
    vector<int> g(4);
    for (int i = 0; i < 4; ++i) {
        g[i] = guess(b[i], b[(i + 1) % 4], b[(i + 2) % 4]);
    }
    vector<int> res;
    for (int i = 0; i < 4; ++i) {
        if (g[1] < max({g[0], g[2], g[3]})) {
            res.push_back(b[i]);
        }
        rotate(g.begin(), g.begin() + 1, g.end());
    }
    return res;
}

void test_case() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i;
    }
    while (n > 2) {
        vector<int> cur;
        if (n == 3) {
            for (int i = 0;; ++i) {
                if (std::find(nums.begin(), nums.end(), i) == nums.end()) {
                    nums.push_back(i);
                    ++n;
                    break;
                }
            }
        }
        for (int i = 0; i + 3 < n; i += 4) {
            for (auto &j : solve(vector<int>{nums[i], nums[i + 1], nums[i + 2], nums[i + 3]})) {
                cur.push_back(j);
            }
        }
        if (n % 4 == 1) {
            cur.push_back(nums.back());
        } else if (n % 4 == 2) {
            cur.push_back(nums[n - 2]);
            cur.push_back(nums[n - 1]);
        } else if (n % 4 == 3) {
            for (auto &i : solve(vector<int>{nums[n - 4], nums[n - 3], nums[n - 2], nums[n - 1]})) {
                if (i != nums[n - 4]) {
                    cur.push_back(i);
                }
            }
        }
        swap(cur, nums);
        n = int(nums.size());
    }
    answer(nums[0], nums.back());
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        mem.clear();
    }
    return 0;
}
