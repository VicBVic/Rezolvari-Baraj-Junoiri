#include <bits/stdc++.h>
using namespace std;
//#define TESTS

#define x first
#define y second
#define pii pair<int,int>
#define veci vector<int>
#define vecp vector<pii>
#define all(x) x.begin(), x.end()
#define pb(x,y) x.push_back(y)

const int maxn = 1e5+5;

int v[maxn];
int s[maxn];
string p;
int n;

void solve()
{
	cin>>n>>p;

	int suminit=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i-1]=='(') v[i]=-1;
		else v[i]=1;

		s[i]=v[i]+s[i-1];
		suminit+=v[i]*i;
	}

	int mn=-2, cntmn=0;
	for(int i=1;i<n;i++)
	{
		if(s[i+1]==0) continue;
		if(v[i]>=v[i+1]) continue;
		cntmn++;
	}

	if(cntmn==0)
	cout<<suminit<<'\n'<<-1<<'\n'<<cntmn<<'\n';
	else
	cout<<suminit<<'\n'<<suminit+mn<<'\n'<<cntmn<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "swap"
		freopen(fname".in","r", stdin);
		freopen(fname".out","w",stdout);
	#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t=1;

	#ifdef TESTS
		cin>>t;
	#endif
	while(t--)
	{
		solve();
	}
	return 0;
}