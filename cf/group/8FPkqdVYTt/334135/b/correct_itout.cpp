
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 1000000000000000000LL;
class Node{
public:
	Node *l, *r;
	int s, e;
	ll sum, maxi;
	Node(int a, int b){
		s = a;
		e = b;
		maxi = 0LL;
		sum = 0LL;
		if(s!=e){
			l = new Node(s,(s+e)/2);
			r = new Node((s+e)/2+1,e);
		}
	}
	void pull(){
		if(s==e){
			return;
		}
		sum = l->sum + r->sum;
		sum = min(sum,inf);
		maxi = max(l->maxi,r->maxi);
	}
	void add(int ind, ll val){
		if(s==ind && e==ind){
			sum += val;
			sum = min(sum,inf);
			maxi = sum;
			return;
		}
		if(ind<=(s+e)/2){
			l->add(ind,val);
		}
		else{
			r->add(ind,val);
		}
		pull();
	}
	ll gsum(int st, int en){
		if(st<=s && e<=en){
			return sum;
		}
		ll ret = 0LL;
		if(st<=(s+e)/2){
			ret += l->gsum(st,en);
		}
		if(en>(s+e)/2){
			ret += r->gsum(st,en);
		}
		ret = min(ret,inf);
		return ret;
	}
	ll getmax(int st, int en){
		if(st<=s && e<=en){
			return maxi;
		}
		ll ret = 0;
		if(st<=(s+e)/2){
			ret = max(ret,l->getmax(st,en));
		}
		if(en>(s+e)/2){
			ret = max(ret,r->getmax(st,en));
		}
		return ret;
	}
};

int main(){
	ifstream in("itout.in");
	ofstream out("itout.out");
	int n;
	ll k;
	in >> n >> k;
	int a[n];
	for(int i = 0; i<n; i++){
		in >> a[i];
	}
	Node *t = new Node(1,n);
	int lis[n];
	int best = 0;
	//lis starting with this node
	for(int i = n-1; i>=0; i--){
		lis[i] = 1 + t->getmax(a[i],n);
		t->add(a[i],lis[i]);
		best = max(best,lis[i]);
	}
	vector<ll> dp[best];
	vector<Node*> seg;
	vector<int> nums[best];
	vector<int> loc[best];
	vector<int> point;
	int id[n];
	for(int i = n-1; i>=0; i--){
		lis[i]--;
		id[i] = nums[lis[i]].size();
		nums[lis[i]].push_back(a[i]);
		loc[lis[i]].push_back(i);
		dp[lis[i]].push_back(0LL);
	}
	for(int i = 0; i<best; i++){
		point.push_back(0);
		seg.push_back(new Node(0,(int)nums[i].size()));
	}
	for(int i = n-1; i>=0; i--){
		if(lis[i]==0){
			dp[lis[i]][id[i]] = 1LL;
			seg[lis[i]]->add(id[i],1LL);
			continue;
		}
		ll cur = 0LL;
		while(point[lis[i]]<nums[lis[i]-1].size() && a[i] > nums[lis[i]-1][point[lis[i]]]){
			point[lis[i]]++;
		}
		cur = seg[lis[i]-1]->gsum(point[lis[i]],nums[lis[i]-1].size());
		dp[lis[i]][id[i]] = cur;
		seg[lis[i]]->add(id[i],cur);
	}
	ll rem = k;
	bool inAns[n+1];
	for(int i = 1; i<=n; i++){
		inAns[i] = true;
	}
	int prev = -1;
	for(int i = best-1; i>=0; i--){
		int use = nums[i].size()-1;
		while(loc[i][use]<prev){
			use--;
		}
		while(dp[i][use]<rem){
			rem -= dp[i][use--];
		}
		prev = loc[i][use];
		inAns[nums[i][use]] = false;
	}
	int sz = 0;
	for(int i = 1; i<=n; i++){
		if(inAns[i]){
			sz++;
		}
	}
	out << sz << endl;
	for(int i = 1; i<=n; i++){
		if(inAns[i]){
			out << i << endl;
		}
	}
	return 0;
}
