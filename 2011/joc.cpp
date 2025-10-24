#include <bits/stdc++.h>
using namespace std;
//#define TESTS

#define int long long
#define x first
#define y second
#define pii pair<int,int>
#define veci vector<int>
#define vecp vector<pii>
#define all(x) x.begin(), x.end()
#define pb(x,y) x.push_back(y)

const int maxn = 5e5+5;

int n,k,p;
int v[maxn];

void solve()
{
	cin>>n>>k>>p;

	int ans=0, id=0;

	for(int i=1;i<=k;i++)
	{
		int nr;
		int zeros=0;
		for(int j=1;j<=p;j++)
		{
			cin>>nr;
			if(nr==0) zeros++;
			else v[nr]=1;
		}

		int mx=0, runsum=0;
		int st=1;
		for(int dr=1;dr<=n;dr++)
		{
			runsum+=dr*v[dr];

			zeros-=(v[dr]==0);
			while(st<=dr&&zeros<0)
			{
				runsum-=st*v[st];
				zeros+=(v[st]==0);
				st++;
			}
			//cout<<"here "<<st<<' '<<dr<<' '<<zeros<<','<<runsum<<'\n';

			mx=max(mx, runsum);
		}

		if(mx>ans)
		{
			ans=mx;
			id=i;
		}

		for(int j=1;j<=n;j++) v[j]=0;
	}

	cout<<id<<' '<<ans<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "joc"
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