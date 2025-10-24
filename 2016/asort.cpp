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

const int maxn = 11;
int n;
int r_val(int k , int r)
{
	if((k+r)%2==1)
	{
		int rval = ((k-1)/2 - (r/2) % (n/2) + n/2) % (n/2);

		return rval*2+1;
	}

	int rval = ((k-1)/2 + r/2) %(n/2);

	return (rval+1)*2;
}

void solve()
{
	int c,r,k,t;
	cin>>c>>n>>r>>k>>t;

	if(c==1)
	{
		cout<<r_val(k, r)<<'\n';
		return;
	}

	if(t%2==0)
	{
		int rval = ((t-1)/2 - r%(n/2) + (n/2)) % (n/2);
		
		//cout<<rval<<'\n';
		cout<<rval*2+1<<' '<<(rval+1)%(n/2)*2 +1<<'\n';
	}
	else
	{
		int rval = ((t-1)/2 + r) % (n/2);

		cout<<(rval-1+(n/2))%(n/2) * 2 + 2<<' '<<rval*2 + 2<<'\n';
	}

}

int32_t main()
{
	#ifndef LOCAL
		#define fname "asort"
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