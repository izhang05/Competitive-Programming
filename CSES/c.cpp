#include <iostream>
#include <bits/stdc++.h>
using namespace std;

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: someone on Codeforces
     * Date: 2017-03-14
     * Source: folklore
     * Description: A short self-balancing tree. It acts as a
     *  sequential container with log-time splits/joins, and
     *  is easy to augment with additional data.
     * Time: $O(\log N)$
     * Status: stress-tested
     */

    struct Node {
        Node *l = nullptr, *r = nullptr;
        int val, y, size = 1;
        Node(int val) : val(val), y(rand()) {}
        void recalc();
    };

    int cnt(Node *n) { return n ? n->size : 0; }
    void Node::recalc() { size = cnt(l) + cnt(r) + 1; }

    template<class F>
    void each(Node *n, F f) {
        if (n) {
            each(n->l, f);
            f(n->val);
            each(n->r, f);
        }
    }

    pair<Node *, Node *> split(Node *n, int k) {
        if (!n)
            return {};
        if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
            auto pa = split(n->l, k);
            n->l = pa.second;
            n->recalc();
            return {pa.first, n};
        } else {
            auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
            n->r = pa.first;
            n->recalc();
            return {n, pa.second};
        }
    }

    Node *merge(Node *l, Node *r) {
        if (!l)
            return r;
        if (!r)
            return l;
        if (l->y > r->y) {
            l->r = merge(l->r, r);
            l->recalc();
            return l;
        } else {
            r->l = merge(l, r->l);
            r->recalc();
            return r;
        }
    }

    Node *ins(Node *t, Node *n, int pos) {
        auto pa = split(t, pos);
        return merge(merge(pa.first, n), pa.second);
    }

    // Example application: move the range [l, r) to index k
    void move(Node *&t, int l, int r, int k) {
        Node *a, *b, *c;
        tie(a, b) = split(t, l);
        tie(b, c) = split(b, r - l);
        if (k <= l)
            t = merge(ins(a, b, k), c);
        else
            t = merge(a, ins(c, b, k - r));
    }

} // namespace kactl
//using namespace kactl;

struct test_scores {

  int k;
  multiset<pair<int, int>> scores;
  vector<int> all_scores;
  int ind_remove = 0;

  int current_median = 0;
  multiset<pair<int, int>>::iterator it = scores.begin(); // iterator to scores.size()/2

  void init(int k) {
    this->k = k;
  }

  void new_score(int score) {
    all_scores.push_back(score);

    int n = scores.size();
    if (scores.empty()) {
      current_median = score;
      scores.insert({score, n});
      it = scores.begin();
    } else {
      int n = scores.size();

      if (score >= current_median) {
        scores.insert({score, n});
        if (n % 2 == 1) {
          it = next(it);
        }
      } else {
        scores.insert({score, n});
        if (n % 2 == 0) {
          it = prev(it);
        }
      }
    }
    current_median = it->first;
    n = scores.size();
    if (n > k) {
      int to_remove = all_scores[ind_remove];
      if (*it == make_pair(to_remove, ind_remove)) {
        if (n % 2 == 1) {
          it = next(it);
          scores.erase(prev(it));
        } else {
          it = prev(it);
          scores.erase(next(it));
        }
      } else {
        if (make_pair(to_remove, ind_remove) > *it) {
          scores.erase({to_remove, ind_remove});
          if (n % 2 == 0) {
            it = prev(it);
          }
        } else {
          scores.erase({to_remove, ind_remove});
          if (n % 2 == 1) {
            it = next(it);
          }
        }
      }
      ++ind_remove;
    }
    current_median = it->first;
  }

  double get_median() {
    int n = scores.size();
    if (n % 2 == 1) {
      return current_median;
    } else {
      return ((double) current_median + prev(it)->first) / 2;
    }
  }
};

// To execute C++, please define "int main()"
int main() {
  test_scores test;
  test.init(3);

  test.new_score(5);
  cout << test.get_median() << "\n";
  test.new_score(12);
  cout << test.get_median() << "\n";
  test.new_score(13);
  cout << test.get_median() << "\n";
  test.new_score(7);
  cout << test.get_median() << "\n";
  test.new_score(12);
  cout << test.get_median() << "\n";
  test.new_score(1);
  cout << test.get_median() << "\n";

}


// Your previous Plain Text content is preserved below:

// This is just a simple shared plaintext pad, with no execution capabilities.

// When you know what language you'd like to use for your interview,
// simply choose it from the dots menu on the tab, or add a new language
// tab using the Languages button on the left.

// You can also change the default language your pads are created with
// in your account settings: https://app.coderpad.io/settings

// Enjoy your interview!
