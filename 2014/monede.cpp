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

const int maxn = 1005;

int n,m;
int v[maxn][maxn];
int med[maxn], rest[maxn];

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>v[j][i];
			//cout<<v[i][j]<<' ';
		}
	}

	for(int i=1;i<=m;i++)
	{
		sort(v[i]+1, v[i]+n+1);
	}
	
	int ans=0,poz=0, neg=0;
	for(int j=1;j<=m;j++)
	{
		med[j] = v[j][n+1/2];
		for(int i=1;i<=n;i++)
		{
			if(v[j][i]<med[j]) neg+=med[j]-v[j][i];
			else poz+=v[j][i]-med[j];
		} 
	}

	ans=min(poz, neg)


	//assert(mn!=maxn*maxn);
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "monede"
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