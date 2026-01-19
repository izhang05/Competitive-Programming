#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else

struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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


void test_case() {
    string s;
    cin >> s;
    int n = s.size();
    int sol = 0;
    map<char, int> cur;
    for (int i = 2; i + 1 < n; i += 2) {
        if (s[i] == 'I' && s[i - 1] != 'I' && s[i + 1] != 'I') {
            if (cur.empty()) {
                ++cur[s[i - 1]];
            }
            ++cur[s[i]], ++cur[s[i + 1]];
        } else {
            vector<int> nums{cur['M'], cur['T'] / 2, (cur['I'] + 1) / 3};
            sol += *min_element(nums.begin(), nums.end());
            cur.clear();
        }
    }
    vector<int> nums{cur['M'], cur['T'] / 2, (cur['I'] + 1) / 3};
    sol += *min_element(nums.begin(), nums.end());
    cur.clear();


    for (int i = 1; i + 1 < n; i += 2) {
        if (s[i] == 'I' && s[i - 1] != 'I' && s[i + 1] != 'I') {
            if (cur.empty()) {
                ++cur[s[i - 1]];
            }
            ++cur[s[i]], ++cur[s[i + 1]];
        } else {
            vector<int> nums{cur['M'], cur['T'] / 2, (cur['I'] + 1) / 3};
            sol += *min_element(nums.begin(), nums.end());
            cur.clear();
        }
    }
    nums = vector<int>{cur['M'], cur['T'] / 2, (cur['I'] + 1) / 3};
    sol += *min_element(nums.begin(), nums.end());
    cur.clear();

    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}






//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//#include <debug.h>
//#else
//
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
//
//#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#endif
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//map<char, int> occ[2];
//
//void test_case() {
//    occ[0].clear(), occ[1].clear();
//    string s;
//    cin >> s;
//    int n = s.size();
//    for (int i = 0; i < n; ++i) {
//        ++occ[i % 2][s[i]];
//    }
//    int sol = 0;
//    for (int i = 2; i + 3 < n; i += 2) {
//        if (occ[1]['M'] < 1 || occ[1]['T'] < 2) {
//            break;
//        }
//        if (s[i] == 'I' && s[i + 2] == 'I' && s[i - 1] != 'I' && s[i + 1] != 'I' && s[i + 3] != 'I') {
//            ++sol;
//            i += 2;
//            occ[1]['M'] -= 1, occ[1]['T'] -= 2;
//        }
//    }
//    for (int i = 1; i + 3 < n; i += 2) {
//        if (occ[0]['M'] < 1 || occ[0]['T'] < 2) {
//            break;
//        }
//        if (s[i] == 'I' && s[i + 2] == 'I' && s[i - 1] != 'I' && s[i + 1] != 'I' && s[i + 3] != 'I') {
//            ++sol;
//            i += 2;
//            occ[0]['M'] -= 1, occ[0]['T'] -= 2;
//        }
//    }
//    cout << sol << "\n";
//}
//
//int main() {
//    setIO("1");
//
//    int test_case_number = 1;
//    cin >> test_case_number;
//    while (test_case_number--) {
//        test_case();
//    }
//    return 0;
//}
