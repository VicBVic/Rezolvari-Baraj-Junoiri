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

const int maxval = 1e9+5;
const int maxn = 20005;
const int maxc = 205;

int n,k, v[maxn], c[maxc];


void solve()
{
	cin>>n>>k;
	for(int i=1;i<maxc;i++)
	{
		c[i]=i*i*i*i;
	}

	int runsum=0, cnt4=0, cntrun=0;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		int dr=maxc-1;
		for(int st=1;st<=dr;st++)
		{
			while(st<dr&&c[st]+c[dr]>v[i]) dr--;

			if(c[st]+c[dr]==v[i])
			{
				cnt4++;
				//cout<<"here "<<v[i]<<' '<<c[st]<<' '<<c[dr]<<'\n';
				break;
			}
		}

		v[i]%=10;
		v[i]=v[i]*v[i]*v[i]*v[i];
		v[i]%=10;

		runsum=(runsum+v[i])%10;
		if(i>=k)
		{
			if(runsum==4) cntrun++;
			runsum=(runsum+10-v[i-k+1])%10;
		}
	}

	cout<<cnt4<<'\n'<<cntrun<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "patru"
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