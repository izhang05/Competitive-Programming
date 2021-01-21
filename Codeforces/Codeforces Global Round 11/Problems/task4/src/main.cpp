#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int> > sol;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (!is_sorted(a.begin(), a.end())) {
        if (a[0] != 1) {
            for (int i = 1; i < n; ++i) {
                if (a[i] == a[0] - 1) {
                    int j;
                    vector<int> cur;
                    if (i != n - 1) {
                        cur.push_back(3);
                        int pre = a[0];
                        for (j = 1; j < n; ++j) {
                            if (a[j] == pre + 1) {
                                ++pre;
                            } else {
                                break;
                            }
                        }
                        cur.push_back(j);
                        cur.push_back(i - j + 1);
                        cur.push_back(n - i - 1);
                    } else {
                        cur.push_back(2);
                        int pre = a[0];
                        for (j = 1; j < n; ++j) {
                            if (a[j] == pre + 1) {
                                ++pre;
                            } else {
                                break;
                            }
                        }
                        cur.push_back(j);
                        cur.push_back(n - j);
                    }
                    vector<int> first;
                    for (int k = 0; k < j; ++k) {
                        first.push_back(a[k]);
                    }
                    vector<int> middle;
                    for (int k = j; k < i + 1; ++k) {
                        middle.push_back(a[k]);
                    }
                    vector<int> last;
                    for (int k = i + 1; k < n; ++k) {
                        last.push_back(a[k]);
                    }
                    a.clear();
                    for (int k : last) {
                        a.push_back(k);
                    }
                    for (int k : middle) {
                        a.push_back(k);
                    }
                    for (int k : first) {
                        a.push_back(k);
                    }
                    sol.push_back(cur);
                    break;
                }
            }
        } else if (a[n - 1] != n) {
            for (int i = 1; i < n; ++i) {
                if (a[i] == a[n - 1] + 1) {
                    int j;
                    vector<int> cur;
                    if (i != 0) {
                        cur.push_back(3);
                        int pre = a[n - 1];
                        for (j = n - 2; j >= 0; --j) {
                            if (a[j] == pre - 1) {
                                --pre;
                            } else {
                                break;
                            }
                        }
                        cur.push_back(i + 1);
                        cur.push_back(j - i);
                        cur.push_back(n - j - 1);
                    } else {
                        cur.push_back(2);
                        int pre = a[n - 1];
                        for (j = n - 2; j >= 0; --j) {
                            if (a[j] == pre - 1) {
                                --pre;
                            } else {
                                break;
                            }
                        }
                        cur.push_back(j);
                        cur.push_back(n - j);
                    }
                    vector<int> first;
                    vector<int> last;
                    vector<int> middle;
                    for (int k = 0; k < i + 1; ++k) {
                        first.push_back(a[k]);
                    }
                    for (int k = i + 1; k < j + 1; ++k) {
                        middle.push_back(a[k]);
                    }
                    for (int k = j + 1; k < n; ++k) {
                        last.push_back(a[k]);
                    }
                    a.clear();
                    for (int k : last) {
                        a.push_back(k);
                    }
                    for (int k : middle) {
                        a.push_back(k);
                    }
                    for (int k : first) {
                        a.push_back(k);
                    }
                    sol.push_back(cur);
                    break;
                }
            }
        } else {
            assert(false);
            int j, pre = a[0];
            for (j = 1; j < n; ++j) {
                if (a[j] == pre + 1) {
                    ++pre;
                } else {
                    break;
                }
            }
            vector<int> cur;
            cur.push_back(2);
            cur.push_back(j);
            cur.push_back(n - j);
            vector<int> first, last;
            for (int i = 0; i < j; ++i) {
                first.push_back(a[i]);
            }
            for (int i = j; i < n; ++i) {
                last.push_back(a[i]);
            }
            a.clear();
            for (int i : last) {
                a.push_back(i);
            }
            for (int i : first) {
                a.push_back(i);
            }
            sol.push_back(cur);
        }
    }
    cout << sol.size() << "\n";
    for (vector<int> i : sol) {
        for (int j = 0; j < i.size() - 1; ++j) {
            cout << i[j] << " ";
        }
        cout << i[i.size() - 1];
        cout << "\n";
    }
    cout << "\n";
    for (int i : a) {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    return 0;
}
