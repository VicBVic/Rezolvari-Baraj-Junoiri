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
int n;
char c[maxn];

int revbit(int x)
{
	int ans=0;
	for(int b=1;b<n;b<<=1)
	{
		ans=(ans<<1) + ((x&b)>0);
	}
	return ans;
}

void solve()
{
	char t; cin>>t; cin.get();
	cin.getline(c,maxn);
	n=strlen(c);
	
	for(int i=0;i<n;i++)
	{
		cout<<c[revbit(i)];
	}
	cout<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "spioni"
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