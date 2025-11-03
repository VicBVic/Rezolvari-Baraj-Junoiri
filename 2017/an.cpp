#include <bits/stdc++.h>
using namespace std;
#define TESTS

#define x first
#define y second
#define pii pair<int,int>
#define veci vector<int>
#define vecp vector<pii>
#define all(x) x.begin(), x.end()
#define pb(x,y) x.push_back(y)

const int maxn = 10005;
//d[i] = daca ai o strategie de castig cu primele i pietre
bool d[maxn];
string s;
void solve()
{
	cin>>s;
	reverse(s.begin(), s.end());
	//doar iei piatra de jos
	d[0]=1;
	for(int i=1;i<s.size();i++)
	{
		//doar iei piatra
		d[i]=(1-d[i-1]);

		if(s[i]==s[i-1])
		{
			d[i] |= (d[i-1]);
		}
	}

	cout<<d[s.size()-1]<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "an"
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