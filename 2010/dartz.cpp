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

const int maxn = 1005;

int v[maxn];

void solve()
{
	int n;
	cin>>n;

	for(int i=1;i<maxn;i++)
	{
		v[i]=i*(i+1)*(i+2);
	}

	n/=2;

	int dr=maxn-1;
	for(int st=1;st<=dr;st++)
	{
		while(st<=dr&&v[st]+v[dr]>n) dr--;
		
		if(v[st]+v[dr]==n)
		{
			cout<<st<<' '<<dr<<' '<<st<<' '<<dr<<'\n';
			return;
		}
	}
}

int main()
{
	#ifndef LOCAL
		#define fname "dartz"
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