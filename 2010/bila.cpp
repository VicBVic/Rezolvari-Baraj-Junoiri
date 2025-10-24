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

const int maxn = 130;

int n, m;
int v[maxn][maxn];
int h[maxn][maxn];

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

void dfs(int i, int j)
{
	if(h[i][j]!=0) return;

	int mn = v[i][j], ni, nj;
	for(int d=0;d<4;d++)
	{
		if(v[i+di[d]][j+dj[d]] < mn)
		{
			ni=i+di[d];
			nj=j+dj[d];
			mn = v[ni][nj];
		}
	}

	if(mn == v[i][j])
	{
		h[i][j]=1;
		return;
	}

	dfs(ni, nj);

	h[i][j]=h[ni][nj]+1;
}

void solve()
{
	memset(v, 0x3f, sizeof(v));

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>v[i][j];
		}
	}

	int maxh=0, minval=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dfs(i,j);
			if(h[i][j]>maxh||(h[i][j]==maxh&&v[i][j]<minval))
			{
				maxh=h[i][j];
				minval=v[i][j];
			}
		}
	}

	cout<<maxh<<' '<<minval<<'\n';
}

int main()
{
	#ifndef LOCAL
		#define fname "bila"
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