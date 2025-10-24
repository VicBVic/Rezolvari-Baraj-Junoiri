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

const int maxn = 505;
const int maxp = 500*500*8;
int n;
int v[maxn][maxn];
int s[maxn][maxn];
int fr[maxn];

int anr, ai[maxp], aj[maxp], ak[maxp], srt[maxp]; 

int partsum( int i, int j, int len)
{
	return s[i][j]-s[i][j-len]-s[i-len][j]+s[i-len][j-len];
}
bool cmp(int a, int b)
{
	return ai[a]<ai[b]||
	(ai[a]==ai[b]&&ak[a]<ak[b]);
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>v[i][j];
		}
	}

	for(int k=2;k<n;k++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				s[i][j]=(v[i][j]<=k);

		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				s[i][j]+=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
		
		for(int i=k;i<=n;i++)
		{
			for(int j=k;j<=n;j++)
			{
				if(partsum(i,j,k)==k*k)
				{
					anr++;
					ai[anr] = i-k+1;
					aj[anr] = j-k+1;
					ak[anr] = k;
					srt[anr] = anr;
				}
			}
		}
	}

	sort(srt+1,srt+anr+1, cmp);

	cout<<anr<<'\n';
	for(int i=1;i<=anr;i++)
	{
		int j=srt[i];
		cout<<ai[j]<<' '<<aj[j]<<' '<<ak[j]<<'\n';
	}
}

int32_t main()
{
	#ifndef LOCAL
		#define fname "latin"
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