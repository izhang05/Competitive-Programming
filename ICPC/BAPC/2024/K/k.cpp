#include <bits/stdc++.h>

using namespace std;

int n;

string str;

struct Node{
    vector<int> vec;

    vector<pair<char, int>> childs;
};

vector<Node> nodes;

int new_node(){
    nodes.push_back({});

    return nodes.size() - 1;
}

int getchild(int v, char c){
    for(auto p : nodes[v].childs){
        if(p.first == c) return p.second;
    }

    nodes[v].childs.push_back({c, new_node()});

    return nodes[v].childs.back().second;
}

int root = new_node();

void add_string(int v, string &s, int indx, int val){
    nodes[v].vec.push_back(val + indx - 1);

    if(indx == s.size()) return;

    add_string(getchild(v, s[indx]), s, indx + 1, val);
}

void print(int v, string str){
    cout << str << ": ";
    for(auto x : nodes[v].vec) cout << x << " ";
    cout << "\n";

    for(auto p : nodes[v].childs) print(p.second, str + p.first);
}

int dfs(int v, int len){
    int curans = 1e9;

    if(len != 0){
        sort(nodes[v].vec.begin(), nodes[v].vec.end());

        int lst = -1, cnt = 0;

        for(auto x : nodes[v].vec){
            if(x - len + 1 > lst){
                cnt++;
                lst = x;
            }
        }

        curans = n - (cnt * len) + cnt + len;
    }

    for(auto p : nodes[v].childs){
        curans = min(curans, dfs(p.second, len + 1));
    }

    return curans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> str;

    n = str.size();

    nodes.reserve(n * n * 5);

    for(int i = n - 1; i >= 0; i--){
        string s = str.substr(i, n - i);

        add_string(root, s, 0, i);
    }

//    print(root, "");

    cout << min(dfs(root, 0), n + 1);
}