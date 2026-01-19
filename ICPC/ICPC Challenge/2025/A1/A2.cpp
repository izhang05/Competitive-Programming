#include <bits/stdc++.h>

using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) { // [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}

uniform_real_distribution<double> dis(0.0, 1.0);

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e3 + 5;

struct mem {
    int l, r, f, ind;
    set<int> facts;

    mem(int l, int r, int ind, const set<int> &facts) {
        this->l = l, this->r = r, this->f = int(facts.size()), this->facts = facts, this->ind = ind;
    }
};


vector<int> dep[mxn], exc[mxn];
set<int> depend[mxn];
int n, m, len, d, e;

set<int> re;

vector<mem> orig_a;

long double get_cost(const set<int> &sol) {
    long double sum_r = 0, sum_l = 0;
    set<int> cur_good, tot_depend;
    set<int> tot_facts;
    for (auto &i: sol) {
        sum_r += orig_a[i].r, sum_l += orig_a[i].l;
        for (auto &j: orig_a[i].facts) {
            tot_facts.insert(j);
        }
    }
    for (auto &i: tot_facts) {
        if (re.find(i) != re.end()) {
            cur_good.insert(i);
        }
        tot_depend.insert(i);
        for (auto &j: depend[i]) {
            tot_depend.insert(j);
        }
    }
    int tot_exc = 0;
    for (auto &i: tot_facts) {
        bool good = false;
        for (auto &j: exc[i]) {
            if (tot_facts.find(j) != tot_facts.end()) {
                good = true;
            }
        }
        tot_exc += good;
    }

//    cout << sum_r << " " << sum_l << " " << len << " " << cur_good.size() << " " << re.size() << " " << tot_facts.size()
//         << " "
//         << tot_exc << " " << tot_depend.size() << "\n";
    if (sum_l >= len) {
        return 0;
    }
    long double res = sum_r * (1 - pow(sum_l / len, 3)) * ((long double) cur_good.size() / re.size()) *
                      ((long double) tot_facts.size() - tot_exc) / tot_depend.size();
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);

    cin >> n >> m >> len >> d >> e;

//    if (n == 5) {
//        cout << "3 1 3 4" << "\n";
//        return 0;
//    }
    vector<mem> a;

    for (int i = 0; i < n; ++i) {
        int l, r, f;
        cin >> l >> r >> f;
        set<int> facts;
        for (int j = 0; j < f; ++j) {
            int cur;
            cin >> cur;
            facts.insert(cur);
        }
        a.emplace_back(l, r, i, facts);
    }
    orig_a = vector<mem>(a.begin(), a.end());

    for (int i = 0; i < d; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        dep[u].push_back(v);
    }
    for (int i = 0; i < 100; ++i) {
        vector<int> vis(100, false);
        vis[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            depend[i].insert(cur);
            for (auto &j: dep[cur]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
    }

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        exc[u].push_back(v);
        exc[v].push_back(u);
    }

    sort(a.begin(), a.end(), [](const auto &left, const auto &right) {
        if (left.l == 0) {
            if (right.l == 0) {
                return left.r > right.r;
            }
            return true;
        }
        if (right.l == 0) {
            return false;
        }
        return left.r / left.l > right.r / right.l;
    });

    for (int i = 0; i < m; ++i) {
        clock_t clock_start = clock();

        int k;
        cin >> k;
        re.clear();
        for (int j = 0; j < k; ++j) {
            int cur;
            cin >> cur;
            re.insert(cur);
        }
//        set<int> orig_re(re.begin(), re.end());
        int sum = 0, sum_r = 0;
        set<int> sol;


        for (auto &j: a) {
            long double old_ratio = (long double) sum / len;
            old_ratio = 1 - pow(old_ratio, 3);
            long double new_ratio = (long double) (sum + j.l) / len;
            new_ratio = 1 - pow(new_ratio, 3);

            if ((sum_r + j.r) * new_ratio > sum_r * old_ratio && sol.find(j.ind) == sol.end()) {
                sum += j.l;
                sum_r += j.r;
                sol.insert(j.ind);
            }
        }

        long double pre = get_cost(sol);
//        cout << pre << "\n";
//        return 0;
        long double temp = 10000, adjust = 0.999;
        while ((clock() - clock_start) / (double) CLOCKS_PER_SEC <= (long double) 0.5 / m) {
            int ind = rnd(0, n - 1);
            if (sol.find(ind) == sol.end()) {
                sol.insert(ind);
            } else {
                sol.erase(ind);
            }
            int cur = get_cost(sol);

            if (cur > pre) {
                pre = cur;
            } else if (cur < pre) {
                long double prob = exp((cur - pre) / temp);
                if (dis(rng) <= prob) {
                    pre = cur;
                } else {
                    if (sol.find(ind) == sol.end()) {
                        sol.insert(ind);
                    } else {
                        sol.erase(ind);
                    }
                }
            }
            temp *= adjust;
        }
//        cout << get_cost(sol) << "\n";

        cout << sol.size();
        for (auto &j: sol) {
            cout << " " << j + 1;
        }
        cout << "\n";
    }
    return 0;
}






//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e3 + 5;
//
//struct mem {
//    int l, r, f, ind;
//    set<int> facts;
//
//    mem(int l, int r, int ind, const set<int> &facts) {
//        this->l = l, this->r = r, this->f = int(facts.size()), this->facts = facts, this->ind = ind;
//    }
//};
//
//vector<int> dep[mxn], exc[mxn];
//set<int> depend[mxn];
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//
//    int n, m, len, d, e;
//    cin >> n >> m >> len >> d >> e;
//
//    if (n == 5) {
//        cout << "3 1 3 4" << "\n";
//        return 0;
//    }
//    vector<mem> a;
//    for (int i = 0; i < n; ++i) {
//        int l, r, f;
//        cin >> l >> r >> f;
//        set<int> facts;
//        for (int j = 0; j < f; ++j) {
//            int cur;
//            cin >> cur;
//            facts.insert(cur);
//        }
//        a.emplace_back(l, r, i, facts);
//    }
//    for (int i = 0; i < d; ++i) {
//        int u, v;
//        cin >> u >> v;
//        --u, --v;
//        dep[u].push_back(v);
//    }
//    for (int i = 0; i < 100; ++i) {
//        vector<int> vis(100, false);
//        vis[i] = true;
//        queue<int> q;
//        q.push(i);
//        while (!q.empty()) {
//            int cur = q.front();
//            q.pop();
//            depend[i].insert(cur);
//            for (auto &j: dep[cur]) {
//                if (!vis[j]) {
//                    vis[j] = true;
//                    q.push(j);
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < e; ++i) {
//        int u, v;
//        cin >> u >> v;
//        --u, --v;
//        exc[u].push_back(v);
//        exc[v].push_back(u);
//    }
//
////    sort(a.begin(), a.end(), [](const auto &left, const auto &right) {
////            if (left.l == 0) {
////                if (right.l == 0) {
////                    return left.r > right.r;
////                }
////                return true;
////            }
////            if (right.l == 0) {
////                return false;
////            }
////            return left.r / left.l > right.r / right.l;
////        });
//
//    for (int i = 0; i < m; ++i) {
//        int k;
//        cin >> k;
//        set<int> re;
//        for (int j = 0; j < k; ++j) {
//            int cur;
//            cin >> cur;
//            re.insert(cur);
//        }
//        set<int> orig_re(re.begin(), re.end());
//        int sum = 0, sum_r = 0;
//        set<int> sol;
//
//        set<int> good_facts, tot_facts;
//        set<int> cur_depend;
//
//        sort(a.begin(), a.end(), [](const auto &left, const auto &right) {
//            if (left.l == 0) {
//                if (right.l == 0) {
//                    return left.r > right.r;
//                }
//                return true;
//            }
//            if (right.l == 0) {
//                return false;
//            }
//            return left.r / left.l > right.r / right.l;
//        });
//
//
//        while (!re.empty()) {
//            int cur = *re.begin();
//            re.erase(cur);
//            for (auto &j: a) {
//                long double old_ratio = (long double) sum / len;
//                old_ratio = 1 - pow(old_ratio, 3);
//                long double new_ratio = (long double) (sum + j.l) / len;
//                new_ratio = 1 - pow(new_ratio, 3);
//                long double old_contain = good_facts.size(), new_contain = old_contain;
//                long double old_tot_facts = tot_facts.size(), new_tot_facts = tot_facts.size();
//                long double old_depend = cur_depend.size(), new_depend = cur_depend.size();
//                set<int> add_depend;
//                for (auto &l: j.facts) {
//                    if (good_facts.find(l) == good_facts.end() && orig_re.find(l) != orig_re.end()) {
//                        ++new_contain;
//                    }
//                    if (tot_facts.find(l) == tot_facts.end()) {
//                        ++new_tot_facts;
//                    }
//                    add_depend.insert(l);
//                    for (auto &i1: depend[l]) {
//                        add_depend.insert(i1);
//                    }
//                }
//                for (auto &l: add_depend) {
//                    if (cur_depend.find(l) == cur_depend.end()) {
//                        ++new_depend;
//                    }
//                }
//                new_contain = pow(new_contain, 1.5);
//                old_contain = pow(old_contain, 1.5);
//
//
////                new_tot_facts = new_depend = old_tot_facts = old_depend = 1;
//                if (new_ratio * (sum_r + j.r) * new_contain * max(1.0l, new_tot_facts) / max(1.0l, new_depend) >
//                    old_ratio * sum_r * old_contain * max(1.0l, old_tot_facts) / max(1.0l, old_depend) &&
//                    sol.find(j.ind) == sol.end() && j.facts.find(cur) != j.facts.end()) {
//                    sum += j.l;
//                    sum_r += j.r;
//                    sol.insert(j.ind);
//                    for (auto &l: j.facts) {
//                        if (orig_re.find(l) != orig_re.end()) {
//                            good_facts.insert(l);
//                        }
//                        tot_facts.insert(l);
//                        cur_depend.insert(l);
//                        re.erase(l);
//                    }
//                    for (auto &l: j.facts) {
//                        for (auto &i1: depend[l]) {
//                            cur_depend.insert(i1);
//                            if (tot_facts.find(i1) == tot_facts.end()) {
//                                re.insert(i1);
//                            }
//                        }
//                    }
//                    break;
//                }
//            }
//        }
//
//
//        for (auto &j: a) {
//            long double old_ratio = (long double) sum / len;
//            old_ratio = 1 - pow(old_ratio, 3);
//            long double new_ratio = (long double) (sum + j.l) / len;
//            new_ratio = 1 - pow(new_ratio, 3);
//            long double old_contain = good_facts.size(), new_contain = old_contain;
//            long double old_tot_facts = tot_facts.size(), new_tot_facts = tot_facts.size();
//            long double old_depend = cur_depend.size(), new_depend = cur_depend.size();
//            set<int> add_depend;
//            for (auto &l: j.facts) {
//                if (good_facts.find(l) == good_facts.end() && orig_re.find(l) != orig_re.end()) {
//                    ++new_contain;
//                }
//                if (tot_facts.find(l) == tot_facts.end()) {
//                    ++new_tot_facts;
//                }
//                add_depend.insert(l);
//                for (auto &i1: depend[l]) {
//                    add_depend.insert(i1);
//                }
//            }
//            for (auto &l: add_depend) {
//                if (cur_depend.find(l) == cur_depend.end()) {
//                    ++new_depend;
//                }
//            }
//            new_contain = pow(new_contain, 1.5);
//            old_contain = pow(old_contain, 1.5);
//
////            new_tot_facts = new_depend = old_tot_facts = old_depend = 1;
//            if (new_ratio * (sum_r + j.r) * new_contain * max(1.0l, new_tot_facts) / max(1.0l, new_depend) >
//                old_ratio * sum_r * old_contain * max(1.0l, old_tot_facts) / max(1.0l, old_depend) &&
//                sol.find(j.ind) == sol.end()) {
//                sum += j.l;
//                sum_r += j.r;
//                sol.insert(j.ind);
//                for (auto &l: j.facts) {
//                    if (orig_re.find(l) != orig_re.end()) {
//                        good_facts.insert(l);
//                    }
//                    tot_facts.insert(l);
//                    cur_depend.insert(l);
//                    re.erase(l);
//                }
//                for (auto &l: j.facts) {
//                    for (auto &i1: depend[l]) {
//                        cur_depend.insert(i1);
//                        if (tot_facts.find(i1) == tot_facts.end()) {
//                            re.insert(i1);
//                        }
//                    }
//                }
//            }
//        }
//
////        sort(a.begin(), a.end(), [](const auto &left, const auto &right) {
////            return left.l < right.l;
////        });
//
//        while (!re.empty()) {
//            int cur = *re.begin();
//            re.erase(cur);
//            for (auto &j: a) {
//                long double old_ratio = (long double) sum / len;
//                old_ratio = 1 - pow(old_ratio, 3);
//                long double new_ratio = (long double) (sum + j.l) / len;
//                new_ratio = 1 - pow(new_ratio, 3);
//                long double old_contain = good_facts.size(), new_contain = old_contain;
//                long double old_tot_facts = tot_facts.size(), new_tot_facts = tot_facts.size();
//                long double old_depend = cur_depend.size(), new_depend = cur_depend.size();
//                set<int> add_depend;
//                for (auto &l: j.facts) {
//                    if (good_facts.find(l) == good_facts.end() && orig_re.find(l) != orig_re.end()) {
//                        ++new_contain;
//                    }
//                    if (tot_facts.find(l) == tot_facts.end()) {
//                        ++new_tot_facts;
//                    }
//                    add_depend.insert(l);
//                    for (auto &i1: depend[l]) {
//                        add_depend.insert(i1);
//                    }
//                }
//                for (auto &l: add_depend) {
//                    if (cur_depend.find(l) == cur_depend.end()) {
//                        ++new_depend;
//                    }
//                }
//                new_contain = pow(new_contain, 1.5);
//                old_contain = pow(old_contain, 1.5);
//
////                new_tot_facts = new_depend = old_tot_facts = old_depend = 1;
//                if (new_ratio * (sum_r + j.r) * new_contain * max(1.0l, new_tot_facts) / max(1.0l, new_depend) >
//                    old_ratio * sum_r * old_contain * max(1.0l, old_tot_facts) / max(1.0l, old_depend) &&
//                    sol.find(j.ind) == sol.end() && j.facts.find(cur) != j.facts.end()) {
//                    sum += j.l;
//                    sum_r += j.r;
//                    sol.insert(j.ind);
//                    for (auto &l: j.facts) {
//                        if (orig_re.find(l) != orig_re.end()) {
//                            good_facts.insert(l);
//                        }
//                        tot_facts.insert(l);
//                        cur_depend.insert(l);
//                        re.erase(l);
//                    }
//                    for (auto &l: j.facts) {
//                        for (auto &i1: depend[l]) {
//                            cur_depend.insert(i1);
//                            if (tot_facts.find(i1) == tot_facts.end()) {
//                                re.insert(i1);
//                            }
//                        }
//                    }
//                    break;
//                }
//            }
//        }
//
//        cout << sol.size();
//        for (auto &j: sol) {
//            cout << " " << j + 1;
//        }
//        cout << "\n";
//    }
//    return 0;
//}





//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e3 + 5;
//
//struct mem {
//    int l, r, f, ind;
//    set<int> facts;
//
//    mem(int l, int r, int ind, const set<int> &facts) {
//        this->l = l, this->r = r, this->f = int(facts.size()), this->facts = facts, this->ind = ind;
//    }
//};
//
//vector<int> dep[mxn], exc[mxn];
//set<int> depend[mxn];
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//
//    int n, m, len, d, e;
//    cin >> n >> m >> len >> d >> e;
//    vector<mem> a;
//    for (int i = 0; i < n; ++i) {
//        int l, r, f;
//        cin >> l >> r >> f;
//        set<int> facts;
//        for (int j = 0; j < f; ++j) {
//            int cur;
//            cin >> cur;
//            facts.insert(cur);
//        }
//        a.emplace_back(l, r, i, facts);
//    }
//    for (int i = 0; i < d; ++i) {
//        int u, v;
//        cin >> u >> v;
//        --u, --v;
//        dep[u].push_back(v);
//    }
//    for (int i = 0; i < 100; ++i) {
//        vector<int> vis(100, false);
//        vis[i] = true;
//        queue<int> q;
//        q.push(i);
//        while (!q.empty()) {
//            int cur = q.front();
//            q.pop();
//            depend[i].insert(cur);
//            for (auto &j: dep[cur]) {
//                if (!vis[j]) {
//                    vis[j] = true;
//                    q.push(j);
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < e; ++i) {
//        int u, v;
//        cin >> u >> v;
//        --u, --v;
//        exc[u].push_back(v);
//        exc[v].push_back(u);
//    }
//    sort(a.begin(), a.end(), [](const auto &left, const auto &right) {
//        return left.r / left.l > right.r / right.l;
//    });
//
//
//    for (int i = 0; i < m; ++i) {
//        int k;
//        cin >> k;
//        set<int> re;
//        for (int j = 0; j < k; ++j) {
//            int cur;
//            cin >> cur;
//            re.insert(cur);
//        }
//        int sum = 0;
//        set<int> facts_used;
//        set<int> sol;
//        while (!re.empty()) {
//            int cur = *re.begin();
//            re.erase(cur);
//            for (auto &j: a) {
//                if (sum + j.l < len / 2 && sol.find(j.ind) == sol.end() && j.facts.find(cur) != j.facts.end()) {
//                    sum += j.l;
//                    sol.insert(j.ind);
//                    for (auto &l: j.facts) {
//                        facts_used.insert(l);
//                        re.erase(l);
//                    }
//                    for (auto &l: j.facts) {
//                        for (auto &i1: depend[l]) {
//                            if (facts_used.find(i1) == facts_used.end()) {
//                                re.insert(i1);
//                            }
//                        }
//                    }
//                    break;
//                }
//            }
//        }
//        for (auto &j: a) {
//            if (sum + j.l < len / 2 && sol.find(j.ind) == sol.end()) {
//                sum += j.l;
//                sol.insert(j.ind);
//            } else {
//                break;
//            }
//        }
//        cout << sol.size();
//        for (auto &j: sol) {
//            cout << " " << j + 1;
//        }
//        cout << "\n";
//    }
//    return 0;
//}
