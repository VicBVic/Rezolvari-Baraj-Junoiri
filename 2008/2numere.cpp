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
int a[maxn], b[maxn], n;

int get_num(int v[])
{
	int ans=0;
	for(int i=1;i<=n;i++) ans=ans*10+v[i];
	return ans;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];

	sort(a+1, a+n+1);
	sort(b+1, b+n+1);

	int anr = 0;
	int bnr = get_num(b);
	int mn = INT_MAX;
	int ansa=0, ansb=0;
	
	bool ok = 1;
	do{

		anr = get_num(a);
		while(bnr <= anr && ok)
		{
			if(mn > anr - bnr)
			{
				mn = anr-bnr;
				ansa = anr;
				ansb = bnr;
			}

			ok = next_permutation(b+1, b+n+1);

			bnr = get_num(b);
		}
	}while(next_permutation(a+1, a+n+1));

	cout<<ansa<<'\n'<<ansb<<'\n'<<mn<<'\n';
}

int main()
{
	#ifndef LOCAL
		#define fname "2numere"
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