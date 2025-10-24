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

const int maxn = 2e5+5;
int n,s,v[maxn];

void solve()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}

	deque<int> q;

	int sum=0, len=0, st=1;
	int best=0, bpoz=0, bh=0;
	for(int dr=1;dr<=n;dr++)
	{
		len++;
		sum+=v[dr];

		while(!q.empty()&&v[q.back()]<v[dr]) q.pop_back();
		
		q.push_back(dr);
	
		while(st<=dr&& len * v[q.front()] - sum >s)
		{
			len--;
			sum-=v[st];

			if(q.front()==st) q.pop_front();
			
			st++;
		}

		if(st<=dr && len * v[q.front()] - sum == s)
		{
			if(best<len||(best==len&& bh < v[q.front()]))
			{
				best = len;
				bpoz = st;
				bh = v[q.front()];
			}
		}
	}

	cout<<best<<' '<<bpoz<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "wall1"
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