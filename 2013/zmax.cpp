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

const int maxn = 505;

int n,m;
int v[maxn][maxn];
int sus[maxn][maxn], jos[maxn][maxn], diag[maxn][maxn];

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>v[i][j];
			diag[i][j]=v[i][j]+diag[i-1][j+1];
		}

		for(int j=1;j<=m;j++)
		{
			sus[i][j]=v[i][j]+max(sus[i][j-1], 0);
		}

		for(int j=m;j>=1;j--)
		{
			jos[i][j]=v[i][j]+max(jos[i][j+1], 0);
		}
	}

	int mx=INT_MIN;
	for(int k=3;k<=min(n,m);k++)
	{
		for(int i=1;i<=n-k+1;i++)
		{
			for(int j=k;j<=m;j++)
			{
				int di = i+k-1, dj=j-k+1;

				int news = diag[di][dj] - diag[i-1][j+1];

				news += sus[i][j-1];
				news += jos[di][dj+1];

				mx=max(mx, news);

			}
		}
	}

	cout<<mx<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "zmax"
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