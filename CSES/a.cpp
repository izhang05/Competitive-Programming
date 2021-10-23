#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n = 4;

bool valid(vector<int> &nums, int cur) {
    int l = int(nums.size());
    for (int i = 0; i < (1 << l); ++i) {
        for (int j = 0; j < (1 << l); ++j) {
            if (i & j) {
                continue;
            }
            int v_i = 0, v_j = 0;
            for (int k = 0; k < l; ++k) {
                if (i & (1 << k)) {
                    v_i |= nums[k];
                }
                if (j & (1 << k)) {
                    v_j |= nums[k];
                }
            }
            if ((v_i | cur) == v_j) {
                return false;
            }
        }
    }
    return true;
}
map<int, set<int>> vals;

set<vector<int>> occ;

void gen(vector<int> nums) {
    sort(nums.begin(), nums.end());
    if (occ.find(nums) != occ.end()) {
        return;
    }
    occ.insert(nums);
    int l = (int) nums.size(), cnt = 0;
    for (int i = 0; i < (1 << n); ++i) {
        if (valid(nums, i)) {
            ++cnt;
            nums.push_back(i);
            gen(nums);
            nums.pop_back();
        }
    }
    vals[l].insert(cnt);
    if (l == n) {
        for (auto &i : nums) {
            cout << i << " ";
        }
        cout << "\n";
    }
    //    if ((1 << n) - (1 << l) != cnt) {
    //        for (auto &i : nums) {
    //            cout << i << " ";
    //        }
    //        cout << cnt << "\n";
    //    }
}

int main() {
    gen(vector<int>{});
    for (auto &i : vals) {
        cout << i.first << ": ";
        for (auto &j : i.second) {
            cout << j << " ";
        }
        cout << (1 << n) - (1 << i.first) << "\n";
    }

    return 0;
}
