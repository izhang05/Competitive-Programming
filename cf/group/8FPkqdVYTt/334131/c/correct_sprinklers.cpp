#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAXN 100000
#define MOD 1000000007

int N;
int x[MAXN], y[MAXN];
int A[MAXN];
int top[MAXN];
int lft[MAXN];
long long sumLeft[MAXN];
long long stairSumLeft[MAXN];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> y[i];
		A[x[i]] = y[i];
	}
	int low = N;
	for(int i=0;i<N;i++)
		while(A[i] < low)
			lft[--low] = i;
	while(low > 0)
		lft[--low] = N;
	sumLeft[N-1] = lft[N-1];
	for(int j=N-2;j>=0;j--)
		sumLeft[j] = (sumLeft[j+1] + lft[j])%MOD;
	stairSumLeft[N-1] = lft[N-1];
	for(int j=N-2;j>=0;j--)
		stairSumLeft[j] = (stairSumLeft[j+1] + ((long long)lft[j])*(N-j))%MOD;

	top[N-1] = A[N-1];
	for(int i=N-2;i>=0;i--)
		top[i] = max(top[i+1],A[i]);

	long long ans = 0;
	int j = N-1;
	for(int i=1;i<N;i++)
	{
		while(j > 0 && lft[j-1] <= i)
			j--;
		long long bad = stairSumLeft[j] - stairSumLeft[top[i]] - (N-top[i])*(sumLeft[j] - sumLeft[top[i]]);
		bad = ((bad%MOD)+MOD)%MOD;
		long long bad2 = (top[i]*((long long)j) - (j*((long long)(j-1)))/2)%MOD;
		bad2 = (bad2*i)%MOD;
		bad = (bad + bad2)%MOD;

		long long tot = ((top[i]*((long long)(top[i]+1)))/2)%MOD;
		tot = (tot*i)%MOD;
		ans = ans + tot - bad;
		ans = ((ans%MOD)+MOD)%MOD;
	}
	cout << ans << '\n';
}