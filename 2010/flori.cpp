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

const int maxn = 905;

int v[maxn*4];
int ans[maxn*4], len[maxn*4], beck[maxn*4];
int n,m;

void afis(int i)
{
	if(i==0) return;
	afis(beck[i]);
	cout<<min(i,2*n-i+1)<<' ';
}

bool compare(int i, int j)
{
	if(ans[i]<ans[j]+v[i]) return 1;
	if(ans[i]==ans[j]+v[i]&&len[i]>len[j]+1) return 1;
	return 0; 
}

void solve()
{
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			v[m-j+i]+=x;
		}
	}

	n=n+m-1;

	for(int i=1;i<=n;i++)
	{
		v[2*n-i+1]=v[i];
	}

	int mx=1;
	for(int i=1;i<=2*n;i++)
	{
		len[i]=1;
		ans[i]=v[i];
		beck[i]=0;

		for(int j=i-1;j>=1;j--)
		{
			if(v[j]<v[i]&&compare(i, j))
			{
				ans[i]=v[i]+ans[j];
				beck[i]=j;
				len[i]=len[j]+1;
			}

			if(((j<=n)^(i<=n))==0)
			{
				if(v[j]==v[i]&&compare(i,j))
				{
					ans[i]=v[i]+ans[j];
					beck[i]=j;
					len[i]=len[j]+1;
				}
			}
	 	}

		//cout<<i<<"    "<<ans[i]<<','<<beck[i]<<','<<v[i]<<'\n';
		if(ans[i]>ans[mx]||(ans[i]==ans[mx]&&len[mx]>len[i]))
			mx=i;
	}

	cout<<ans[mx]<<'\n'<<len[mx]<<'\n';
	afis(mx);
	cout<<'\n';
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "flori"
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