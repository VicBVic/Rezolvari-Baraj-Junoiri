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

const int maxn = 5005;
const int maxval = 5000;
int n,k;
int v[maxn][maxn];

int sum(int i, int j, int len)
{
	return v[i][j] - v[i-len][j] - v[i][j-len] + v[i-len][j-len];
}

bool ok(int len)
{
	if(len>maxval) return 1;
	for(int i=len;i<=maxval;i++)
	{	
		for(int j=len;j<=maxval;j++)
		{
			if(sum(i,j,len)>=k) return 1;
		}
	}
	return 0;
}

void solve()
{
	cin>>n>>k;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		v[x][y]++;
	}


	for(int i=1;i<=maxval;i++)
	{
		for(int j=1;j<=maxval;j++)
		{
			v[i][j]+=v[i][j-1]+v[i-1][j]-v[i-1][j-1];
		}
	}

	int ans=0;
	for(int b=(1<<20);b>=1;b>>=1)
	{
		if(!ok(ans+b)) ans+=b;
	}

	cout<<ans<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "puncte"
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