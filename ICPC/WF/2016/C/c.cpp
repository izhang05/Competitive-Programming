#include <bits/stdc++.h>

using namespace std;

int n, k;

struct Node{
    int val;
    Node *lft, *rght;

    Node(int val_) : val(val_), lft(nullptr), rght(nullptr) {}
};

void add(Node* &node, int val){
    if(node == nullptr) node = new Node(val);
    else{
        if(val < node->val) add(node->lft, val);
        else add(node->rght, val);
    }
}

Node* maketree(vector<int> vec){
    Node* root = new Node(vec[0]);

    for(int i = 1; i < vec.size(); i++){
        add(root, vec[i]);
    }

    return root;
}

int hshval = 0;

map<pair<int, int>, int> mp;

int gethsh(Node* node){
    if(node == nullptr) return 0;
    else{
        pair<int, int> p = {gethsh(node->lft), gethsh(node->rght)};

        auto it = mp.find(p);

        if(it != mp.end()) return it->second;
        else return mp[p] = ++hshval;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    cin >> n >> k;

    set<int> st;

    for(int i = 0; i < n; i++){
        vector<int> v(k);

        for(auto &x : v) cin >> x;

        Node *root = maketree(v);

        st.insert(gethsh(root));
    }

    cout << st.size();
}