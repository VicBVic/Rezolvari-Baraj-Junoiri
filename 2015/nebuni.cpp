#include <bits/stdc++.h>
using namespace std;

#define int long long
//#define TESTS

#define x first
#define y second
#define pii pair<int,int>
#define veci vector<int>
#define vecp vector<pii>
#define all(x) x.begin(), x.end()
#define pb(x,y) x.push_back(y)

const int maxn = 1e6+5;

int prin[2*maxn], sec[2*maxn];
int n,m;

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		
		prin[x+n-y]=1;
		sec[x+y-1]=1;
	}

	for(int i=2;i<2*n;i++)
	{
		prin[i]+=prin[i-2];
		sec[i]+=sec[i-2];
	}



	int ans=0;
	for(int i=1;i<2*n;i++)
	{
		if(prin[i]==prin[max(i-2,0ll)])
		{
			int j=min(i, 2*n-i);

			ans+=j;


			ans-=sec[n+j-1]-sec[max(0ll,n-j+1-2)];
		}
	}

	cout<<ans<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "nebuni"
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