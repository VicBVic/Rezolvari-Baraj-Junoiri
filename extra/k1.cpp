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

const int maxn = 1e6+5;

int n;
int v[maxn];
priority_queue<int, vector<int>, greater<int>> pq;

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>v[i], pq.push(v[i]);
	int ans=0;
	while(pq.size()>1)
	{
		int st=pq.top(); pq.pop();
		int dr=pq.top(); pq.pop();

		ans+=st+dr;
		pq.push(st+dr);
	}

	cout<<ans<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "k1"
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