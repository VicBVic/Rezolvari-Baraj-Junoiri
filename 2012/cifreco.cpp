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

const int maxn = 30;

int c[maxn][maxn];
int n;
void precalc()
{
	for(int i=0;i<=n+8;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			//cout<<c[i][j]<<' ';
		}
		//cout<<'\n';
	}
}

int stars_bars(int n, int k)
{
	return c[n+k-1][k-1];
}

int getval(string x)
{
	int ans=0;
	int sumx=8;
	for(int i=0;i<n-1;i++)
	{
		int cif=x[i]-'0';
		for(int j=1;j<cif;j++)
		{
			ans+=stars_bars(sumx-j+1,n-i-1);
		}
		//cout<<"here "<<x<<' '<<ans<<'\n';
		sumx-=cif-1;
	}
	return ans;
}

void solve()
{
	cin>>n;
	precalc();
	string x,y;
	cin>>x>>y;

	int valx=getval(x), valy=getval(y);
	cout<<valy-valx+1<<'\n';

}

int32_t main()
{
	#ifndef LOCAL
		#define fname "cifreco"
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