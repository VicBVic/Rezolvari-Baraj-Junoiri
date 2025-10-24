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

const int maxn = 5e6+5;
int ciur[maxn];
int fr[maxn];
int n;
long long ans=0;

void doCiur()
{
	for(int i=2;i<=n;i++)
	{
		if(ciur[i]==1)
		{
			for(int j=i;j<=n;j+=i) ciur[j]*=i;
		}
	}
}

void secondCiur()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i*2;j<=n;j+=i)
		{
			ans+=1ll*fr[j]*fr[i];
		}
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) ciur[i]=1;
	doCiur();
	for(int i=1;i<=n;i++)
	{
		//cout<<ciur[i]<<' ';
		fr[ciur[i]]++;
	}
	//cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<' '<<fr[i]<<'\n';
		ans+=2ll*fr[i]*fr[i] - fr[i];
	}
	secondCiur();
	cout<<ans<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "adn"
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