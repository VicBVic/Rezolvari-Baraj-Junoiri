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

int v[maxn][maxn];
int d[4][maxn][maxn];
int n,m;

bool corner_a(int i, int j)
{
	return (i==1&&j==1)||(i==n&&j==m);
}

bool corner_b(int i, int j)
{
	return (i==1&&j==m)||(i==n&&j==1);
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>v[i][j];
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(corner_b(i,j)) continue;
			d[0][i][j]=v[i][j]+max(d[0][i-1][j], d[0][i][j-1]);
		}

		for(int j=m;j>=1;j--)
		{
			if(corner_a(i,j)) continue;
			d[1][i][j]=v[i][j]+max(d[1][i-1][j], d[1][i][j+1]);
		}
	}

	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(corner_a(i,j)) continue;
			d[2][i][j]=v[i][j]+max(d[2][i+1][j], d[2][i][j-1]);
		}

		for(int j=m;j>=1;j--)
		{
			if(corner_b(i,j)) continue;
			d[3][i][j]=v[i][j]+max(d[3][i+1][j], d[3][i][j+1]);
		}
	}

	int ans=0, bi=1, bj=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(corner_a(i,j)) continue;
			if(corner_b(i,j)) continue;
			int newans = d[0][i][j]+d[1][i][j]+d[2][i][j]+d[3][i][j] - 2*v[i][j];
			
			if(newans>ans)
			{
				ans=newans;
				bi=i;
				bj=j;
			}
		}
	}

	cout<<ans<<'\n'<<bi<<' '<<bj<<'\n';
}

int main()
{
	#ifndef LOCAL
		#define fname "poteci"
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